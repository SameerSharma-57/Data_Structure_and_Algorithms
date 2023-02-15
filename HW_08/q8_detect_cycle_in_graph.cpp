#include <iostream>
#define INT_MAX 1000
#define int long long int
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
using namespace std;

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
    // for (int i = 0; i < n; i++)
    // {
    //     arr[i]->color='w';
    // }
    Queue<int> q;
    q.push(s);
    // cout<<s<<" ";
    arr[s]->color = 'g';
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        // cout<<u<<endl;
        // for (int i = 0; i < n; i++)
        // {
        //     cout<<arr[i]->color<<" ";
        // }
        // cout<<endl;
        for (int j = 0; j < arr[u]->adj_size; j++)
        {

            if (arr[arr[u]->adj[j]]->color == 'w')
            {
                arr[arr[u]->adj[j]]->color = 'g';
                // if(u==3){
                //     cout<<"neighbour "<<arr[u]->adj_size<<endl;
                // }
                // cout<<arr[u]->adj[j]<<endl;
                // cout<<arr[u]->adj[j]<<" ";
                arr[arr[u]->adj[j]]->parent = u;
                q.push(arr[u]->adj[j]);
            }
            else if (arr[arr[u]->adj[j]]->color == 'g')
            {
                cout<<u<<" "<<arr[u]->adj[j]<<endl;
                return 1;
            }
        }
        
        arr[u]->color = 'b';
        
    }
    return 0;
}
int32_t main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    if (n == 0)
    {
        return 0;
    }
    Node *arr[n];
    int temp;
    for (int i = 0; i < n; i++)
    {
        arr[i] = new Node(n);
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int u, v;
        cin >> u >> v;
        arr[u - 1]->insert(v - 1);
        arr[v - 1]->insert(u - 1);
    }
    
    

    bool flag=0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]->color == 'w' && bfs(arr,n,i))
        {
            flag=1;
            break;
        }
    }
    if(flag){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < arr[i]->adj_size; j++)
    //     {
    //         cout<<arr[i]->adj[j]<<" ";
    //     }
    //     cout<<endl;

    // }

    return 0;
}