#include <iostream>

using namespace std;
#define INT_MAX 1000
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
bool isSafe(int *arr[], int n, int m, int x, int y, bool *visited[])
{
    return ((x >= 0) && (x < n) && (y < m) && (y >= 0) && (arr[x][y]) && (!visited[x][y]));
}

void bfs(int *arr[], int n, int m, int x, int y, bool *visited[])
{
    static int horizontal[] = { 0, 0,  1, -1};
    static int vertical[] = {  1, -1, 0, 0};
    // cout << x << ',' << y << " ";
    visited[x][y] = 1;
    Queue<int *> q;
    int temp[] = {x, y};
    q.push(temp);
    while (!q.empty())
    {
        int u = q.front()[0];
        int v = q.front()[1];
        q.pop();
        cout << endl
             << u << ',' << v << " ";

        for (int i = 0; i < 4; i++)
        {
            if (isSafe(arr, n, m, u + vertical[i], v + horizontal[i], visited))
            {
                cout << u + vertical[i] << ',' << v + horizontal[i] << " ";
                visited[u + vertical[i]][v + horizontal[i]] = 1;
                int* temp = new int[2]{u + vertical[i], v + horizontal[i]};

                q.push(temp);
            }
        // if (q.size() > 0)
        // {
        //     cout << "now queue is: ";
        //     for (int i = q._front; i <= q._back; i++)
        //     {
        //         cout << q.arr[i][0] << q.arr[i][1] << " ";
        //     }
        // }
        }
    }
}

int noOfIslands(int *arr[], int n, int m, bool *visited[])
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] && !visited[i][j])
            {

                bfs(arr, n, m, i, j, visited);
                // cout << endl;
                // for (int i = 0; i < n; i++)
                // {
                //     for (int j = 0; j < m; j++)
                //     {
                //         cout << visited[i][j] << " ";
                //     }
                //     cout << endl;
                // }
                // cout << endl;
                count++;
            }
        }
    }
    return count;
}
int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    int *arr[n];
    for (int i = 0; i < n; i++)
    {
        int *temp = new int[m];
        for (int j = 0; j < m; j++)
        {
            int t;
            cin >> t;

            temp[j] = t;
        }

        arr[i] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
        
    }
    

    // cout << endl;

    bool *visited[n];

    for (int i = 0; i < n; i++)
    {
        bool *temp = new bool[m];
        for (int j = 0; j < m; j++)
        {
            temp[j] = 0;
        }

        visited[i] = temp;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << visited[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << noOfIslands(arr, n, m, visited) << endl;
    // visited[1][3]=1;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << visited[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}