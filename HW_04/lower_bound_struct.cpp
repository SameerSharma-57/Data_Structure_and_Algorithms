#include <iostream>
using namespace std;

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

int search(Node* root,int val){
    Node* temp=root;
    int out=-1;
    while(temp!=NULL){
        if(temp->data<val){
            temp=temp->right;
        }
        else if(temp->data>val){
            out=temp->data;
            temp=temp->left;

        }
        else{
            return val;
        }
    }
    return out;
}
int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n,q;
    cin>>n>>q;
    
    Node* root=NULL;
    int temp;
    cin>>temp;
    root=insert(root,temp);
    
    for (int i = 0; i < n-1; i++)
    {
        cin>>temp;
        insert(root,temp);
    }
    for (int i = 0; i < q; i++)
    {
        int val;
        cin>>val;
        cout<<search(root,val)<<endl;
    }

    return 0;
}