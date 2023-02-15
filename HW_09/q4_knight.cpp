#include <iostream>
using namespace std;
#define INT_MAX 500000
template <class T>
class Queue
{
public:
    T arr[INT_MAX];
    int _back = -1;
    int _front = 0;
    int currSize = 0;

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
        cout << "overflow" << endl;
    }

    void pop()
    {
        if (!this->empty())
        {
            currSize--;
            _front++;
            return;
        }
        cout << "queue is empty" << endl;
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

    int size()
    {
        return currSize;
    }
};
typedef struct Node
{
    int x;
    int y;
    int dis;
    bool visited;
    Node() : visited(0) {}
    Node(int a, int b, int d)
    {
        x = a;
        y = b;
        dis = d;
    }
} Node;

bool isInside(int x, int y, int n, int m)
{
    return ((x >= 0) && (x < n + 1) && (y >= 0) && (y < m + 1));
}

int minimumNoOfStepsForKnight(int n, int m, int kx, int ky, int fx, int fy)
{
    if (kx == fx && ky == fy)
    {
        return 0;
    }
    Queue<Node *> q;
    q.push(new Node(kx, ky, 0));
    int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[] = {1, -1, 2, -2, 2, -2, 1, -1};
    bool visit[n+1][n+1];
    // bool **visit=new bool*[n+1];
    // for (int i = 0; i < n+1; i++)
    // {
    //     bool* temp=new bool[n+1];
    //     temp={0};
    //     visit[i]=temp;
    // }
    
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            visit[i][j] = 0;
        }
    }
    visit[kx][ky] = 1;

    int d = 0;
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int u = temp->x + dy[i];
            int v = temp->y + dx[i];
            if (isInside(u, v, n, m) && !visit[u][v])
            {
                visit[u][v] = 1;
                if (u == fx && v == fy)
                {
                    return temp->dis + 1;
                }
                q.push(new Node(u, v, (temp->dis + 1)));
            }
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

    int n, m, kx, ky, fx, fy;
    cin >> n >> m >> kx >> ky >> fx >> fy;
    if (isInside(fx, fy, n, m))
    {
        cout << (minimumNoOfStepsForKnight(n, m, kx, ky, fx, fy));
    }
    else
    {
        cout << "-1";
    }

    return 0;
}