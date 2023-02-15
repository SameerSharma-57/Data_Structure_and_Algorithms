#include <iostream>
using namespace std;
#define int long long int
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

    bool search(BST *root, int val)
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

    int pathToNode(BST *root, int val)
    {

        int flag = 0;
        flag = flag ^ root->data;
        if (root->data == val)
        {

            return flag;
        }
        else if (root->data > val)
        {
            return flag ^ pathToNode(root->left, val);
        }
        return flag ^ pathToNode(root->right, val);
    }

    void printInOrder(BST *root)
    {
        if (root == NULL)
        {
            return;
        }
        printInOrder(root->left);
        cout << root->data << " ";
        printInOrder(root->right);
    }

    void printPreOrder(BST *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->data << " ";
        printInOrder(root->left);
        printInOrder(root->right);
    }
};
int32_t main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    BST b;
    BST *root = NULL;
    int n, q;
    cin >> n;
    int arr[n];
    int temp, x;
    cin >> temp;
    arr[0] = temp;
    root = b.insert(root, temp);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> temp;
        arr[i + 1] = temp;
        b.insert(root, temp);
    }
    // b.printInOrder(root);
    // cout<<endl;
    // b.printPreOrder(root);
    // cout<<endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }

    // cout<<b.pathToNode(root,arr[0]);
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x == y)
        {
            cout << arr[x] << endl;
        }
        else
        {
            cout << (b.pathToNode(root, arr[x]) ^ b.pathToNode(root, arr[y])) << endl;
        }
    }

    return 0;
}