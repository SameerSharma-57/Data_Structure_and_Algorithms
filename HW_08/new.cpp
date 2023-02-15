#include <iostream>
#define ll long long int
using namespace std;
class Node
{
public:
    ll data;
    Node *left;
    Node *right;
    Node(ll d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

// unordered_map<ll,ll> mp;
Node *Build_Tree(ll inO[], ll preO[], ll start, ll end, ll *pre_order_index, ll n, ll arr[])
{
    if (start > end || *pre_order_index >= n)
    {
        return NULL;
    }
    ll root_index = arr[preO[*pre_order_index]];
    Node *root = new Node(inO[root_index]);
    *pre_order_index += 1;
    root->left = Build_Tree(inO, preO, start, root_index - 1, pre_order_index, n, arr);
    root->right = Build_Tree(inO, preO, root_index + 1, end, pre_order_index, n, arr);
    return root;
}
bool Target_sum(Node *node, ll sum)
{
    if (node == NULL)
    {
        return false;
    }
    bool possible = false;
    sum = sum - node->data;
    if (sum == 0 && node->left == NULL && node->right == NULL)
    {
        return true;
    }
    if (node->left)
    {
        possible = possible || Target_sum(node->left, sum);
    }
    if (node->right)
    {
        possible = possible || Target_sum(node->right, sum);
    }
    return possible;
}
void printInorder(Node *node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n;
    cin >> n;
    ll x;
    cin >> x;
    ll inO[n];
    ll preO[n];
    ll arr[1000000];
    for (ll i = 0; i < n; i++)
    {
        cin >> preO[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> inO[i];
    }
    ll pre_order_index = 0;
    for (ll i = 0; i < n; ++i)
    {
        arr[inO[i]] = i;
    }
    Node *root = Build_Tree(inO, preO, 0, n - 1, &pre_order_index, n, arr);
    // printInorder(root);
    if (Target_sum(root, x))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}