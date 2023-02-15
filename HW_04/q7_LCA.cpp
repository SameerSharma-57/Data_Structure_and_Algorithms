#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    Node *left = NULL;
    Node *right = NULL;
} Node;

Node *insert(Node *root, int val)
{
    if (root == NULL)
    {
        Node *n = new Node;
        n->data = val;
        n->left = NULL;
        n->right = NULL;
        return n;
    }
    else if (root->data < val)
    {
        root->right = insert(root->right, val);
    }
    else
    {
        root->left = insert(root->left, val);
    }
    return root;
}
bool search(Node *root, int val)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->data < val)
    {
        return search(root->right, val);
    }
    else if (root->data > val)
    {
        return search(root->left, val);
    }
    return 1;
}
int lca(Node *root, int p, int q)
{
    
    int high = p > q ? p : q;
    int low = p > q ? q : p;
    Node *temp = root;
    Node *prev = NULL;
    if (!search(root, p) || !search(root, q))
    {
        return -1;
    }
    while (temp != NULL)
    {
        if (temp->data == low || temp->data == high)
        {
            return temp->data;
        }
        if (temp->data < low)
        {
            temp = temp->right;
        }
        else if (temp->data > high)
        {
            temp = temp->left;
        }
        
    }
    return -1;
}
int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, q;
    cin >> n >> q;
    Node *root = NULL;
    int temp;
    cin >> temp;
    root = insert(root, temp);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> temp;
        insert(root, temp);
    }
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << lca(root, x, y) << endl;
    }

    return 0;
}