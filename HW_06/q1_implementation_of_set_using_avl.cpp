#include <iostream>
using namespace std;
# define int long long 
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
template <class T>
int balance(Node<T> *root)
{
    return height(root->left) - height(root->right);
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
Node<T> *findInOrderSuccessor(Node<T> *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
template <class T>
void insertInAVL(Node<T> *&root, int val)
{

    if (root == NULL)
    {
        root = new Node<T>(val, NULL, NULL);
        return;
    }
    else if (val < root->data)
    {
        insertInAVL(root->left, val);
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
        insertInAVL(root->right, val);
        if (balance(root) == -2)
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
// template<class T>
// Node<T>* deleteNode(Node<T>*& root, T key)
// {
	
// 	// STEP 1: PERFORM STANDARD BST DELETE
// 	if (root == NULL)
// 		return root;

// 	// If the key to be deleted is smaller
// 	// than the root's key, then it lies
// 	// in left subtree
// 	if ( key < root->key )
// 		root->left = deleteNode(root->left, key);

// 	// If the key to be deleted is greater
// 	// than the root's key, then it lies
// 	// in right subtree
// 	else if( key > root->key )
// 		root->right = deleteNode(root->right, key);

// 	// if key is same as root's key, then
// 	// This is the node to be deleted
// 	else
// 	{
// 		// node with only one child or no child
// 		if( (root->left == NULL) ||
// 			(root->right == NULL) )
// 		{
// 			Node *temp = root->left ?
// 						root->left :
// 						root->right;

// 			// No child case
// 			if (temp == NULL)
// 			{
// 				temp = root;
// 				root = NULL;
// 			}
// 			else // One child case
// 			*root = *temp; // Copy the contents of
// 						// the non-empty child
// 			free(temp);
// 		}
// 		else
// 		{
// 			// node with two children: Get the inorder
// 			// successor (smallest in the right subtree)
// 			Node* temp = findInOrderSuccessor(root->right);

// 			// Copy the inorder successor's
// 			// data to this node
// 			root->key = temp->key;

// 			// Delete the inorder successor
// 			root->right = deleteNode(root->right,
// 									temp->key);
// 		}
// 	}

// 	// If the tree had only one node
// 	// then return
// 	if (root == NULL)
// 	return root;

// 	// STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
// 	root->height = 1 + max(height(root->left),
// 						height(root->right));

// 	// STEP 3: GET THE BALANCE FACTOR OF
// 	// THIS NODE (to check whether this
// 	// node became unbalanced)
// 	int balance = balance(root);
    

// 	// If this node becomes unbalanced,
// 	// then there are 4 cases

// 	// Left Left Case
// 	if (balance > 1 &&
// 		getBalance(root->left) >= 0)
// 		return RotateWithLeftChild(root);

// 	// Left Right Case
// 	if (balance > 1 &&
// 		getBalance(root->left) < 0)
// 	{
// 		root->left = RotateWithRightChild(root->left);
// 		return RotateWithLeftChild(root);
// 	}

// 	// Right Right Case
// 	if (balance < -1 &&
// 		getBalance(root->right) <= 0)
// 		return RotateWithRightChild(root);

// 	// Right Left Case
// 	if (balance < -1 &&
// 		getBalance(root->right) > 0)
// 	{
// 		root->right = RotateWithLeftChild(root->right);
// 		return RotateWithRightChild(root);
// 	}

// 	return root;
// }

template <class T>
Node<T>* deleteNode(Node<T> *&root, T val)
{
    if (root == NULL)
    {
        return root;
    }
    else if (val < root->data)
    {
        root->left=deleteNode(root->left, val);
    }
    else if (val > root->data)
    {
        root->right=deleteNode(root->right, val);
    }
    else
    {
        Node<T> *temp;
        if (!root->right && !root->left)
        {
            // temp = root;
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
            T d = temp->data;
            deleteNode(root, temp->data);
            root->data = d;
        }
    }
    if (root == NULL)
    {
        return root;
    }
    root->height = max(height(root->left), height(root->right)) + 1;
    // int balanceOfRoot=balance(root);
    if (balance(root) >= 2 && balance(root->left) >= 0)
    {
        RotateWithLeftChild(root);
    }
     if (balance(root) == 2 && balance(root->left) < 0)
    {
        DoubleRotateWithLeftChild(root);
    }
    if (balance(root) <= -2 && balance(root->right) >= 0)
    {
        RotateWithRightChild(root);
    }
    if (balance(root) <= -2 && balance(root->right) < 0)
    {
        DoubleRotateWithRightChild(root);
    }
    return root;
}

class Set
{
private:
    Node< int> *root = NULL;
    int curr_size = 0;

public:
    void insert( int data)
    {
        if (!this->check(data))
        {
            curr_size += 1;
            insertInAVL(root, data);
        }
        // curr_size += 1;
    }
    void erase( int data)
    {
        deleteNode(root, data);
    }
     int size()
    {
        return curr_size;
    }
     int empty()
    {
        return curr_size == 0 ? 1 : 0;
    }
     int lower_bound( int x)
    {
        Node< int> *temp = root;
        if(root==NULL){
            return -1;
        }
         int out=root->data;
        while (temp != NULL)
        {
            if (temp->data == x)
            {
                return x;
            }
            else if (temp->data < x)
            {
                temp = temp->right;
            }
            else
                
                {
                    out = temp->data;
                    temp = temp->left;
                }
        }
        if (out > x)
        {
            return out;
        }
        return -1;
    }
     int upper_bound( int x)
    {
        Node< int> *temp = root;
        if(root==NULL){
            return -1;
        }
         int out = root->data;
        while (temp != NULL)
        {
            if (temp->data == x)
            {
    
                if (temp->left)
                {
                    temp = temp->left;
                }
                else
                {
                    temp = temp->right;
                }
            }
            else if (temp->data < x)
            {
                temp = temp->right;
            }
            else

            {
                out = temp->data;
                temp = temp->left;
            }
            
        }
        if (out > x)
        {
            return out;
        }
        return -1;
    }
     int check(int x)
    {
        if (this->lower_bound(x) == x)
        {
            return 1;
        }
        return 0;
    }
    void display(){
        preOrder(root);
        cout<<endl;
    }
    int rootData(){
        return root->data;
    }
};
int32_t main()
{
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
   
    

    int cases;
    cin >> cases;
    Set s;
     int out = 0;
    int temp;
    for (int i = 0; i < cases; i++)
    {
         int x;
        cin >> temp;
        if (temp == 1)
        {

            cin >> x;
            s.insert(x);
        }
        else if (temp == 2)
        {

            cin >> x;
            s.erase(x);
        }
        else if (temp == 3)
        {
            out += s.size();
        }
        else if (temp == 4)
        {
            out += s.empty();
        }
        else if (temp == 5)
        {
            cin >> x;
            out += s.lower_bound(x);
        }
        else if (temp == 6)
        {
            cin >> x;
            out += s.upper_bound(x);
        }
        else if (temp == 7)
        {
            cin >> x;
            out += s.check(x);
        }
    }
    cout << out << endl;

    return 0;
}