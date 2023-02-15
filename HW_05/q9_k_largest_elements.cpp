#include <iostream>
using namespace std;
# define INT_MAX 100
template <class int>
class Stack
{
    int arr[INT_MAX];
    int _top;

public:
    Stack(): _top(-1) {}

    void push(int x)
    {
        arr[++_top] = x;
    }

    void pop()
    {
        if (_top < 0)
        {
            cout << "stack is empty" << endl;
            return;
        }
        _top--;
    }

    int top()
    {
        
        return arr[_top];
    }

    int size()
    {
        cout << _top + 1 << endl;
        return _top + 1;
    }

    bool empty()
    {
        if (_top < 0)
        {

            return true;
        }
        return false;
    }
};
typedef struct Node{
    int data;
    Node* left=NULL;
    Node* right=NULL;

    

}Node;

Node* insert(Node* root,int val){
    if(root==NULL){
        Node* n=new Node;
        n->data=val;
        return n;

    }
    else if(root->data<val){
        root->right=insert(root->right,val);
    }
    else{
        root->left=insert(root->left,val);
    }
    return root;
}

void FindKLargestElements(Node* root,int k){
    if(root==NULL){
        return;
    }
    Node* temp=root;
    Stack<Node*> st;
    int i=0;
    while((temp!=NULL ||!st.empty())&& i<k){
        while(temp!=NULL){
            st.push(temp);
            temp=temp->right;
        }
        temp=st.top();
        st.pop();
        cout<<temp->data<<" ";
        i++;
        temp=temp->left;
    }

}
int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin>>n;
    if(n<=0){
        cout<<endl;
        return 0;
    }
    Node* root=NULL;
    int temp;
    cin>>temp;
    root=insert(root,temp);
    for (int i = 0; i < n-1; i++)
    {
        cin>>temp;
        insert(root,temp);
    }
    int k;
    cin>>k;
    FindKLargestElements(root,k);
    
    return 0;
}