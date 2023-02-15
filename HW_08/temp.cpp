/* C++ program to construct tree using
inorder and preorder traversals */
#include <iostream>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
class node
{
	public:
	int data;
	node* left;
	node* right;
};

/* Prototypes for utility functions */
int search(int arr[], int strt, int end, int value);
node* newNode(int data);

/* Recursive function to construct binary
of size len from Inorder traversal in[]
and Preorder traversal pre[]. Initial values
of inStrt and inEnd should be 0 and len -1.
The function doesn't do any error checking
for cases where inorder and preorder do not
form a tree */
node* buildTree(int in[], int pre[], int inStrt, int inEnd)
{
	static int preIndex = 0;

	if (inStrt > inEnd)
		return NULL;

	/* Pick current node from Preorder
	traversal using preIndex
	and increment preIndex */
	node* tNode = newNode(pre[preIndex++]);

	/* If this node has no children then return */
	if (inStrt == inEnd)
		return tNode;

	/* Else find the index of this node in Inorder traversal */
	int inIndex = search(in, inStrt, inEnd, tNode->data);

	/* Using index in Inorder traversal, construct left and
	right subtress */
	tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
	tNode->right = buildTree(in, pre, inIndex + 1, inEnd);

	return tNode;
}

/* UTILITY FUNCTIONS */
/* Function to find index of value in arr[start...end]
The function assumes that value is present in in[] */
int search(int arr[], int strt, int end, int value)
{
	int i;
	for (i = strt; i <= end; i++)
	{
		if (arr[i] == value)
			return i;
	}
}

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return (Node);
}

/* This function is here just to test buildTree() */
void printInorder(node* node)
{
	if (node == NULL)
		return;

	/* first recur on left child */
	printInorder(node->left);

	/* then print the data of node */
	cout<<node->data<<" ";

	/* now recur on right child */
	printInorder(node->right);
}

/* Driver code */
int main()
{
	// char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
	// char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
	// int len = sizeof(in) / sizeof(in[0]);
    int n,target;
    cin>>n>>target;
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
	node* root = buildTree(inOrder, preOrder, 0, n - 1);

	/* Let us test the built tree by
	printing Inorder traversal */
	cout << "Inorder traversal of the constructed tree is \n";
	printInorder(root);
}

// This is code is contributed by rathbhupendra
