#include <iostream>
using namespace std;

#define int long long int
struct Node
{
    int data;
    char color;
    Node *left;
    Node *right;
    Node *parent;
    Node() {}
    Node(int d)
    {
        data = d;
        color = 'r';
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};

class RB_Tree
{
public:
    Node *root;
    Node* nil;


    void RotateLeft(Node *&);
    void RotateRight(Node *&);
    void insertion_fixup(Node *);
    void transplant(Node *&, Node *&);
    void delete_fixup(Node *&);
    Node *TreeMinimum(Node *);


    RB_Tree() : root(NULL) {
        

    }
    bool insert(Node *);
    bool deletion(int);
    Node *search(int);
    Node *upperBound(int);
};

void RB_Tree::RotateLeft(Node *&x)
{
    Node *y = x->right;
    x->right = y->left;
    if (y->left != NULL)
    {

        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL)
    {
        root = y;
    }
    else if (x->parent->left == x)
    {
        x->parent->left = y;
    }
    else
    {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}
void RB_Tree::RotateRight(Node *&x)
{
    Node *y = x->left;
    x->left = y->right;
    if (y->right != NULL)
    {

        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL)
    {
        root = y;
    }
    else if (x->parent->left == x)
    {
        x->parent->left = y;
    }
    else
    {
        x->parent->right = y;
    }
    y->right = x;
    x->parent = y;
}

void RB_Tree::insertion_fixup(Node *x)
{

    while (x->parent != NULL && x->parent->color == 'r')
    {
        if (x->parent->parent->left = x->parent)
        {
            Node *y = x->parent->parent->right;
            if (y->color == 'r')
            {
                x->parent->color = 'b';
                y->color = 'b';
                x->parent->parent->color = 'r';
                x = x->parent->parent;
            }
            else
            {
                if (x == x->parent->right)
                {
                    x = x->parent;
                    RotateLeft(x);
                }
                x->parent->color = 'b';
                x->parent->parent->color = 'r';
                RotateRight(x->parent->parent);
            }
        }
        else
        {
            Node *y = x->parent->parent->left;
            if (y->color == 'r')
            {
                x->parent->color = 'b';
                y->color = 'b';
                x->parent->parent->color = 'r';
                x = x->parent->parent;
            }
            else
            {
                if (x == x->parent->left)
                {
                    x = x->parent;
                    RotateRight(x);
                }
                x->parent->color = 'b';
                x->parent->parent->color = 'r';
                RotateLeft(x->parent->parent);
            }
        }
    }
    root->color = 'b';
}

void RB_Tree::transplant(Node *&x, Node *&y)
{
    if (x->parent == NULL)
    {
        root = y;
    }
    else if (x == x->parent->left)
    {
        x->parent->left = y;
    }
    else
    {
        x->parent->right = y;
    }
}
void RB_Tree::delete_fixup(Node *&x)
{
    while (x != root && x->color == 'b')
    {
        if (x == x->parent->left)
        {
            Node *w = x->parent->right;
            if (w->color == 'r')
            {
                w->color = 'b';
                x->parent->color = 'r';
                RotateLeft(x->parent);
                w = x->parent->right;
            }
            if (w->right->color == 'b' && w->left->color == 'b')
            {
                w->color = 'r';
                x = x->parent;
            }
            else
            {
                if (w->right->color == 'b')
                {
                    w->left->color = 'b';
                    w->color = 'r';
                    RotateRight(w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = 'r';
                w->right->color = 'b';
                RotateLeft(w);
                x = root;
            }
        }
        else
        {
            Node *w = x->parent->left;
            if (w->color == 'r')
            {
                w->color = 'b';
                x->parent->color = 'r';
                RotateLeft(x->parent);
                w = x->parent->left;
            }
            if (w->right->color == 'b' && w->left->color == 'b')
            {
                w->color = 'r';
                x = x->parent;
            }
            else
            {
                if (w->left->color == 'b')
                {
                    w->right->color = 'b';
                    w->color = 'r';
                    RotateLeft(w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = 'r';
                w->left->color = 'b';
                RotateRight(w);
                x = root;
            }
        }
    }
    x->color = 'b';
    root->color = 'b';
}

Node *RB_Tree::TreeMinimum(Node *x)
{
    Node *temp = x;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return x;
}

bool RB_Tree::insert(Node *x)
{
    Node *temp = root;
    Node *y = NULL;
    while (temp != NULL)
    {
        y = temp;
        if (temp->data == x->data)
        {
            return 0;
        }
        else if (x->data < temp->data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    x->parent = y;
    if (y == NULL)
    {
        root = x;
    }
    else if (x->data < y->data)
    {
        y->left = x;
    }
    else
    {
        y->right = x;
    }
    x->color = 'r';
    x->right = NULL;
    x->left = NULL;

    insertion_fixup(x);
    return 1;
}

Node *RB_Tree::search(int x)
{
    Node *temp = root;
    while (temp != NULL)
    {
        if (temp->data == x)
        {
            return temp;
        }
        else if (temp->data < x)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
    return temp;
}
bool RB_Tree::deletion(int d)
{
    Node *x = search(d);
    if (x == NULL)
    {
        return 0;
    }
    Node *y = x;
    char y_color = x->color;
    Node *z;
    if (x->left == NULL)
    {
        z = x->right;
        transplant(x, x->right);
    }
    else if (x->right == NULL)
    {
        z = x->left;
        transplant(x, x->right);
    }
    else
    {
        y = TreeMinimum(x->right);
        y_color = y->color;
        z = y->right;
        if (y->parent == x)
        {
            z->parent = y;
        }
        else
        {
            transplant(y, z);
            y->right = x->right;
            y->right->parent = y;
        }
        transplant(x, y);
        y->left = x->left;
        y->left->parent = y;
        y->color = x->color;
    }
    if (y_color == 'b')
    {
        delete_fixup(z);
    }
    return 1;
}

Node *RB_Tree::upperBound(int x)
{
    Node *temp = root;
    Node *u = NULL;
    while (temp != NULL)
    {
        if (temp->data == x)
        {
            break;
        }
        else if (x < temp->data)
        {
            u = temp;
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    if (temp->data == x)
    {
        if (temp->right != NULL)
        {
            return TreeMinimum(temp->right);
        }
    }
    return u;
}

class Set
{

public:
    RB_Tree RB;
    int curr_size;
    Set() : curr_size(0) {}
    void insert(int x)
    {
        Node *temp = new Node(x);
        if (RB.insert(temp))
        {
            curr_size++;
        }
    }
    void erase(int x)
    {
        if (RB.deletion(x))
        {
            curr_size--;
        }
    }
    int size()
    {
        return curr_size;
    }
    int empty()
    {
        if (curr_size == 0)
        {
            return 1;
        }
        return 0;
    }

    int lower_bound(int x)
    {
        if (RB.search(x) != NULL)
        {
            return x;
        }
        Node *ub = RB.upperBound(x);
        if (ub != NULL)
        {
            return ub->data;
        }
        return -1;
    }
    int upper_bound(int x)
    {
        cout << "upper_bound in class" << endl;
        Node *ub = RB.upperBound(x);
        if (ub != NULL)
        {
            return ub->data;
        }
        cout << "returned value" << endl;
        return -1;
    }

    int check(int x)
    {
        if (RB.search(x) != NULL)
        {
            return 1;
        }
        return 0;
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

    int x;
    int out = 0;

    for (int _ = 0; _ < cases; _++)
    {
        int q;
        cin >> q;
        if (q == 1)
        {

            cin >> x;
            s.insert(x);
            cout << "inserted" << endl;
        }
        else if (q == 2)
        {
            cin >> x;
            s.erase(x);
            cout << "deleted" << endl;
        }
        else if (q == 3)
        {
            out += s.size();
            cout << "size"
                 << " ";
            cout << s.size() << endl;
        }
        else if (q == 4)
        {
            out += s.empty();
            cout << "empty"
                 << " ";
            cout << s.empty() << endl;
        }
        else if (q == 5)
        {
            cin >> x;
            cout << "lower bound ";
            cout << s.lower_bound(x) << endl;
            out += s.lower_bound(x);
        }
        else if (q == 6)
        {
            cin >> x;
            cout << "upper bound ";
            cout << s.upper_bound(x) << endl;
            out += s.upper_bound(x);
        }
        else if (q == 7)
        {
            cin >> x;
            cout<<(s.RB.root->data)<<endl;
        }
    }
    cout << out << endl;

    return 0;
}