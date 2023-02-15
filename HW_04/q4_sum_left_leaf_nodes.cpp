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
        n->left=NULL;
        n->right=NULL;
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

int sumOfLeftLeafNodes(Node* root){
    
    int out=0;
    if(root==NULL){
        return out;
    }
    Node* temp=root;
    Stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        temp=st.top();
        st.pop();
        
        if(temp->left){
            Node* t=temp->left;
            if(!t->left && !t->right){
                out+=t->data;

            }
            st.push(t);
        }
        if(temp->right){
            st.push(temp->right);
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
    int n;
    cin>>n;
    Node* root = NULL;
    int temp;
    cin>>temp;
    root=insert(root,temp);
    for (int i = 0; i < n-1; i++)
    {
        cin>>temp;
        insert(root,temp);
    }
    cout<<sumOfLeftLeafNodes(root);
    return 0;
}