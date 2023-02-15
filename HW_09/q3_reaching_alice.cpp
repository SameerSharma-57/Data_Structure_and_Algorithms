#include <iostream>
using namespace std;

#define INT_MAX 1000

template <class T>
class Queue
{
    T arr[INT_MAX];
    int _back = -1;
    int _front = 0;
    int currSize = 0;

public:
    bool empty()
    {
        if (currSize > 0)
        {
            return 0;
        }
        return 1;
    }
    void push(T x)
    {
        if (currSize <= INT_MAX)
        {
            _back++;
            if (_back >= INT_MAX)
            {
                _back = 0;
            }
            arr[_back] = x;
            currSize++;
            return;
        }
        // cout << "overflow" << endl;
    }

    void pop()
    {
        if (!this->empty())
        {
            currSize--;
            _front++;
            return;
        }
        // cout << "queue is empty" << endl;
        return;
    }

    T front()
    {

        return arr[_front];
    }

    T back()
    {
        return arr[_back];
    }

    T size()
    {
        return currSize;
    }
};

class Node
{
public:
    char color;
    int *adj;
    int adj_size = 0;
    int parent;
    Node(int n = 0)
    {
        color = 'w';
        adj = new int[n];
        adj_size = 0;
        parent = -1;
    }
    void insert(int x)
    {
        adj[adj_size++] = x;
    }
};

bool bfs(Node *arr[], int n, int s)
{
    bool out = 0;
    for (int i = 0; i < n; i++)
    {
        arr[i]->color = 'w';
    }
    Queue<int> q;
    q.push(s);
    // cout << s << " ";
    arr[s]->color = 'g';
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int j = 0; j < arr[u]->adj_size; j++)
        {
            if (arr[arr[u]->adj[j]]->color == 'w')
            {
                arr[arr[u]->adj[j]]->color = 'g';
                if (arr[u]->adj[j] == (n-1))
                {
                    return 1;
                }
               

                // cout<<arr[u]->adj[j]<<" ";
                arr[arr[u]->adj[j]]->parent = u;
                q.push(arr[u]->adj[j]);
            }
        }
        arr[u]->color = 'b';
    }
    return 0;
}
int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m, k;
    cin >> n >> m >> k;
    Node *arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new Node(n);
    }

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x != k && y != k)
        {
            arr[x - 1]->insert(y - 1);
            arr[y - 1]->insert(x - 1);
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < arr[i]->adj_size; j++)
    //     {
    //         cout<<arr[i]->adj[j]<<" ";
    //     }
    //     cout<<endl;
        
    // }
    cout<<bfs(arr,n,0);
    
    

    return 0;
}