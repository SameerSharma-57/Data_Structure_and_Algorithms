#include <iostream>
using namespace std;
# define int long long int
typedef struct Node
{
    char color;
    int data;
    Node *left;
    Node *right;
    Node *parent;

    Node() {}
    Node(int d)
    {
        color = 'w';
        data = d;
        left = NULL;
        right = NULL;
        parent = NULL;
    }

} Node;

int search(int arr[],int start,int end,int x){
    
    for (int i = start; i < end; i++)
    {
        if(arr[i]==x){
            return i;
        }
    }
    return -1;
    
}
int preIndex=0;
Node *Build_tree(int inOrder[], int preOrder[], int start, int end,bool b=1)
{
    if(b){
        preIndex=0;
    }
    if(start>end){
        return NULL;
    }
    Node* p=new Node(preOrder[preIndex++]);
    if(start==end){
        return p;
    }

    int inIndex=search(inOrder,start,end,p->data);
    p->left=Build_tree(inOrder,preOrder,start,inIndex-1,0);
    p->right=Build_tree(inOrder,preOrder,inIndex+1,end,0);
    
    return p;

    
}

void printInOrder(Node* root){
    if(root==NULL){
        return;
    }
    printInOrder(root->left);
    cout<<root->data<<" ";
    printInOrder(root->right);

}

void printPreOrder(Node* root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    
    printPreOrder(root->left);
    printPreOrder(root->right);
}

bool Target_sum(Node* root,int sum){
    // if(root==NULL){
    //     if(sum==0){

    //     }
        
    // }

    sum-=root->data;
    
    if(sum==0 && root->left==NULL && root->right==NULL){
        return true;
    }
    else if(root->left!=NULL && Target_sum(root->left,sum)){
        return true;
    }
    else if(root->right!=NULL && Target_sum(root->right,sum)){
        return true;
    }
    return false;




}
int32_t main()
{
    #ifndef ONLINE_MODE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n,target;
    cin>>n>>target;
    if(n==0){
        cout<<"false"<<endl;
        return 0;
    }
    int inOrder[n];
    int preOrder[n];
    for (int i = 0; i < n; i++)
    {
        cin>>preOrder[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>inOrder[i];
    }
    Node* root=Build_tree(inOrder,preOrder,0,n-1);
    // printInOrder(root);
    // cout<<endl;
    // printPreOrder(root);
    if(Target_sum(root,target)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    
    return 0;
}