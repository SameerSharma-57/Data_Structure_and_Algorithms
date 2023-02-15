#include <iostream>
using namespace std;

int max(int m1, int m2)
{
    return m1 > m2 ? m1 : m2;
}

template <class T>
struct Node
{
    T data;
    Node *left;
    Node *right;
    int height;

    Node(T d, Node *lt, Node *rt, int h = 0) : data(d), left(lt), right(rt), height(h) {}
};
template <class T>
int height(Node<T> *root)
{
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        return root->height;
    }
}
template<class T>
int balance(Node<T>* root){
    return height(root->left)-height(root->right);

}
template <class T>
void RotateWithLeftChild(Node<T> *&root)
{
    Node<T> *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    root->height = max(height(root->left), height(root->right)) + 1;
    temp->height = max(height(temp->left), height(temp->right)) + 1;
    root = temp;
}
template <class T>
void RotateWithRightChild(Node<T> *&root)
{
    Node<T> *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    root->height = max(height(root->left), height(root->right)) + 1;
    temp->height = max(height(temp->left), height(temp->right)) + 1;
    root = temp;
}
template <class T>
void DoubleRotateWithLeftChild(Node<T> *&root)
{
    RotateWithRightChild(root->left);
    RotateWithLeftChild(root);
}
template <class T>
void DoubleRotateWithRightChild(Node<T> *&root)
{
    RotateWithLeftChild(root->right);
    RotateWithRightChild(root);
}

template <class T>
Node<T>* findInOrderSuccessor(Node<T> *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
template <class T>
void insert(Node<T> *&root, int val)
{
    // cout<<"Insert called "<<val<<endl;
    if (root == NULL)
    {
        root = new Node<T>(val, NULL, NULL);
        return;
    }
    else if (val < root->data)
    {
        insert(root->left, val);
        if (balance(root) == 2)
        {

            if (val < root->left->data)
            {
                RotateWithLeftChild(root);
            }
            else
            {
                DoubleRotateWithLeftChild(root);
            }
        }
    }
    else if (val > root->data)
    {
        insert(root->right, val);
        if (balance(root)== -2)
        {
            if (val > root->right->data)
            {
                RotateWithRightChild(root);
            }
            else
            {
                DoubleRotateWithRightChild(root);
            }
        }
    }

    root->height = max(height(root->left), height(root->right)) + 1;
    // cout<<"success"<<endl;
}
template <class T>
void deleteNode(Node<T> *&root, T val)
{
    if (root == NULL)
    {
        return;
    }
    else if (val < root->data)
    {
        deleteNode(root->left, val);
    }
    else if (val > root->data)
    {
        deleteNode(root->right, val);
    }
    else
    {
        Node<T> *temp;
        if (!root->right && !root->left)
        {
            //temp = root;
            root = NULL;
        }
        else if (!root->right || !root->left)
        {
            temp = root->right ? root->right : root->left;
            *root = *temp;
        }
        else
        {
            temp = findInOrderSuccessor(root->right);
            T d=temp->data;
            deleteNode(root,temp->data);
            root->data = d;
            // Node<T>* temp1=root->right;
            // while(temp1->left!=temp){
            //     temp1=temp1->right;
            // }
            // temp1->left=NULL;
            
            
            // temp = NULL;
            
        }
        //free(temp);
    }
    if(root==NULL){
        return;
    }
    root->height=max(height(root->left),height(root->right))+1;
    // int balanceOfRoot=balance(root);
    if(balance(root)>=2 && balance(root->left)>=0){
        RotateWithLeftChild(root);
    }
    else if(balance(root)==2 && balance(root->left)<0){
        DoubleRotateWithLeftChild(root);
    }
    else if(balance(root)<=-2 && balance(root->right)>=0){
        RotateWithRightChild(root);
    }
    else if(balance(root)<=-2 && balance(root->right)<0){
        DoubleRotateWithRightChild(root);
    }

}
template <class T>
void preOrder(Node<T> *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
int main()
{
// #ifndef ONLINE_MODE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    // Node<int> *root = NULL;
    // int n;
    // // n=2;
    // // insert(root,1);
    // // insert(root,3);

    // cin >> n;
    // int temp;
    // for (int i = 0; i < n; i++)
    // {

    //     cin >> temp;
    //     insert(root, temp);
    // }
    // cout << root->data << endl;
    // preOrder(root);
    // cout << endl;
    // deleteNode(root, 9);
    // cout << root->data << endl;
    // preOrder(root);
    // cout<<endl;
    // insert(root,2);
    // insert(root,10);
    // insert(root,7);
    // preOrder(root);
    // cout<<endl;
    // deleteNode(root,2);
    // preOrder(root);
    int temp;
    cin>>temp;
    Node<int>* root=NULL;
    while(temp!=4){
        if(temp==1){
            int n;
            cin>>n;
            int t;
            for (int i = 0; i < n; i++)
            {
                cin>>t;
                insert(root,t);
            }
            
        }
        else if(temp==2){
            int d;
            cin>>d;
            deleteNode(root,d);
        }
        else if(temp==3){
            preOrder(root);
            cout<<endl;
        }
        cin>>temp;

    }


    return 0;
}