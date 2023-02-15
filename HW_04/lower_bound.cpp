#include <iostream>
using namespace std;

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

    int search(BST *root, int val,int prev=-1)
    {
        if (root == NULL)
        {
            // cout<<"Hi"<<endl;
            return prev;
        }
        
        else if (root->data < val)
        {
            // cout<<"left"<<endl;
            
            return search(root->right, val,prev);
        }
        else if (root->data > val)
        {
            // cout<<"right"<<endl;
            prev=root->data;
            return search(root->left, val,prev);
        }
        return root->data;
    }
};
int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n,q;
    cin>>n>>q;
    BST b;
    BST* root=NULL;
    int temp;
    cin>>temp;
    root=b.insert(root,temp);
    
    for (int i = 0; i < n-1; i++)
    {
        cin>>temp;
        b.insert(root,temp);
    }
    for (int i = 0; i < q; i++)
    {
        int val;
        cin>>val;
        cout<<b.search(root,val)<<endl;
    }
    
    
    return 0;
}