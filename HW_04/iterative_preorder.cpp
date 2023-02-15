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
class BST
{
private:
    int data;
    BST *left;
    BST *right;
    

public:

    BST() {}
    BST(int d) : data(d), left(NULL), right(NULL) {}
    BST *insert(BST *root, int d)
    {
        if (root == NULL)
        {
            return new BST(d);
        }

        if (d > root->data)
        {
            root->right = insert(root->right, d);
        }
        else
        {
            root->left = insert(root->left, d);
        }
        return root;
    }
    void iterativePreorder(BST* root){
    if(root==NULL){
        return;
    }
    BST* temp=root;
    Stack<BST*> st;
    st.push(root);
    while(!st.empty()){
        temp=st.top();
        st.pop();
        cout<<temp->data<<" ";
        if(temp->left){
            st.push(temp->left);
        }
        if(temp->right){
            st.push(temp->right);
        }
    }
    
}
};


int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin>>n;
    BST b;
    BST* root = NULL;
    int temp;
    cin>>temp;
    root=b.insert(root,temp);
    for (int i = 0; i < n-1; i++)
    {
        cin>>temp;
        b.insert(root,temp);
    }
    b.iterativePreorder(root);
    


    return 0;
}