#include <iostream>
using namespace std;
typedef struct Node
{
    int data;

    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
} Node;
Node *insertAtEnd(Node *end, int x)
{
    Node *n = new Node(x);
    end->next = n;
    n->next = NULL;
    return n;
}

void solve(Node *head)
{
    if (head == NULL)
    {
        cout << endl;
        return;
    }
    Node *slow = head;
    Node *tmp = slow;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        tmp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (tmp == slow)
    {
        cout << endl;
        return;
    }
    else
    {
        tmp->next = slow->next;
        Node *t = head;
        cout << t->data;
        t = t->next;
        while (t != NULL)
        {
            cout << " " << t->data;
            t = t->next;
        }
        cout << endl;
    }
}
int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int n;
        cin >> n;
        Node *head = NULL;
        if (n == 0)
        {
            cout << endl;
        }

        else
        {
            int temp = 0;
            cin >> temp;
            head = new Node(temp);
            Node *end = head;
            for (int j = 0; j < n - 1; j++)
            {
                cin >> temp;
                end = insertAtEnd(end, temp);
            }
            solve(head);
        }
    }

    return 0;
}