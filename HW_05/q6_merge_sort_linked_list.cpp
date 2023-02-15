#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    Node *next;
    Node(){}
    Node(int val){
        data=val;
        next=NULL;
    }

} Node;

Node *insert(Node *end, int val)
{
    if(end==NULL){
        return new Node(val);
    }
    Node *n = new Node;
    n->data = val;
    n->next = NULL;
    end->next = n;
    return n;
}

void print(Node *h)
{
    while (h != NULL)
    {
        cout << h->data << " ";
        h=h->next;
    }
    cout << endl;
}

Node *merge(Node *h1, Node *h2)
{
    Node *temp = new Node;
    Node *out = new Node;
    out=temp;
    while (h1 != NULL || h2 != NULL)
    {
        if(h1==NULL){
            temp->next=h2;
            h2=h2->next;
        }
        else if(h2==NULL){
            temp->next=h1;
            h1=h1->next;
        }
        else if (h1->data <= h2->data)
        {
            temp->next = h1;
            h1 = h1->next;    
        }
        else
        {
            temp->next = h2;
            h2 = h2->next;
        }
        temp = temp->next;
    }

    // while (h1 != NULL)
    // {
    //     temp->next = h1;
    //     h1 = h1->next;
    //     temp = temp->next;
    // }
    // while (h2 != NULL)
    // {
    //     temp->next = h2;
    //     h2 = h2->next;
    //     temp = temp->next;
    // }
    return out->next;
}

Node *findMiddle(Node *h)
{
    if(h->next==NULL){
        return h;
    }
    Node *slow = h;
    
    
    Node *fast = h->next;
    
    while ((fast != NULL && fast->next != NULL))
    {
        
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *mergeSort(Node *h)
{
    if (h->next == NULL)
    {
        return h;
    }
    Node *mid = new Node;
    
    Node *h2 = new Node;
    mid=findMiddle(h);
    h2=mid->next;
    mid->next = NULL;
    Node* out=merge(mergeSort(h),mergeSort(h2));
    return out;
}
// Node* merge(Node* firstNode, Node* secondNode)
// {
//     Node* merged = new Node;
//     Node* temp = new Node;
  
    // merged is equal to temp so in the end we have the top
    // Node.
    // // merged = temp;
  
    // while either firstNode or secondNode becomes NULL
//     while (firstNode != NULL && secondNode != NULL) {
  
//         if (firstNode->data <= secondNode->data) {
//             temp->next = firstNode;
//             firstNode = firstNode->next;
//         }
  
//         else {
//             temp->next = secondNode;
//             secondNode = secondNode->next;
//         }
//         temp = temp->next;
//     }
  
//     // any remaining Node in firstNode or secondNode gets
//     // inserted in the temp List
//     while (firstNode != NULL) {
//         temp->next = firstNode;
//         firstNode = firstNode->next;
//         temp = temp->next;
//     }
  
//     while (secondNode != NULL) {
//         temp->next = secondNode;
//         secondNode = secondNode->next;
//         temp = temp->next;
//     }
//     // return the head of the sorted list
//     return merged->next;
// }
  
// // function to calculate the middle Element
// Node* middle(Node* head)
// {
//     Node* slow = head;
//     Node* fast = head->next;
  
//     while (!slow->next && (!fast && !fast->next)) {
//         slow = slow->next;
//         fast = fast->next->next;
//     }
//     return slow;
// }
  
// // function to sort the given list
// Node* sort(Node* head)
// {
  
//     if (head->next == NULL) {
//         return head;
//     }
  
//     Node* mid = new Node;
//     Node* head2 = new Node;
//     mid = middle(head);
//     head2 = mid->next;
//     mid->next = NULL;
//     // recursive call to sort() hence diving our problem,
//     // and then merging the solution
//     Node* finalhead = merge(sort(head), sort(head2));
//     return finalhead;
// }
int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << endl;
        return 0;
    }
    Node *head = new Node;
    int temp;
    cin >> temp;
    head->data = temp;
    head->next = NULL;
    Node *end = head;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> temp;
        end = insert(end, temp);
    }
     head=mergeSort(head);
    head=mergeSort(head);
    print(head);

    // Node* head1=NULL;
    // Node* head2=NULL;
    // head1=insert(head1,1);
    // Node* end= head1;
    // end=insert(end,3);
    // end=insert(end,5);
    // head2=insert(head2,2);
    // end=head2;
    // end=insert(end,4);
    // end=insert(end,6);
    // end=insert(end,8);
    // print(head1);
    // print(head2);
    // // cout<<findMiddle(head2)->data<<endl;
    // print(merge(head1,head2));
    // // print(mergeSort(head2));
    return 0;
}

//Destroy(this.gameObject);
//Destroy(this);