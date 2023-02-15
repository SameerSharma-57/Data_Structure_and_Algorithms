#include <iostream>
using namespace std;

int max_size = 100;
//#define INT_MAX 10000
template <class T>
class Queue
{
    int capacity = 100;
    T *arr;
    int _back = -1;
    int _front = 0;
    int currSize = 0;

public:
    Queue() : capacity(10000), arr(new int[10000]), currSize(0) {}
    void reserve(int newSize)
    {
        capacity = newSize;
        int *newArr = new int[newSize];
        
        for (int i = 0; i < currSize; i++)
        {
            newArr[i] = arr[i];
        }
        int *temp = arr;
        cout << "reserve called in queue" << endl;
        arr = newArr;
        delete[] temp;
    }
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
        if (currSize >= capacity)
        {
            this->reserve(2 * capacity + 1);
        }

        _back++;
        if (_back >= capacity)
        {
            _back = 0;
        }
        arr[_back] = x;
        currSize++;
        return;

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

    T size()
    {
        return currSize;
    }
};
class Node
{
private:
    int capacity = 100;
    int *neighbour;
    int noOfNeighbour = 0;
    int _size = 0;

public:
    Node() : noOfNeighbour(0), neighbour(new int[1]), capacity(1), _size(-1){};
    void reserve(int newSize)
    {
        capacity = newSize;
        int *newArr = new int[newSize];
        for (int i = 0; i < _size; i++)
        {
            newArr[i] = neighbour[i];
        }
        int *temp = neighbour;
        cout << "reserve called" << endl;
        neighbour = newArr;
        delete[] temp;
    }

    int cnt_neighbors()
    {
        return noOfNeighbour;
    }

    int decrease_cnt_neighbors()
    {
        noOfNeighbour--;
    }
    int operator[](int ind)
    {
        if (ind <= _size)
        {
            return neighbour[ind];
        }
        return -1;
    }
    int size()
    {
        return _size + 1;
    }
    int insert(int x)
    {
        _size++;
        noOfNeighbour++;
        if (_size >= capacity)
        {
            reserve(capacity * 2 + 1);
        }
        neighbour[_size] = x;
    }
};

int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    Node arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < arr[i].size(); j++)
    //     {
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;

    // }

    int count[n] = {0};
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[x - 1].insert(y - 1);
        arr[y - 1].insert(x - 1);
    }
    Queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].cnt_neighbors() <= 1)
        {
            q.push(i);
            count[i] = 1;
        }
    }
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (int i = 0; i < arr[temp].size(); i++)
        {
            if (arr[arr[temp][i]].cnt_neighbors() > 1)
            {
                arr[arr[temp][i]].decrease_cnt_neighbors();
                if (arr[arr[temp][i]].cnt_neighbors() == 1)
                {
                    count[arr[temp][i]] = count[temp] + 1;
                    q.push(arr[temp][i]);
                }
            }
        }
    }
    int out = 0;
    for (int i = 0; i < n; i++)
    {
        if (count[i] > k)
        {
            out += 1;
        }
    }
    cout << out;

    // for (int i = 0; i < n-1; i++)
    // {
    //     cout<<i+1<<"\t";
    //     for (int j = 0; j < arr[i].size(); j++)
    //     {
    //         cout<<arr[i][j]+1<<" ";
    //     }
    //     cout<<'\t'<<arr[i].cnt_neighbors();
    //     cout<<endl;
    // }

    // Node arr;
    // arr.insert(3);
    // arr.insert(8);

    // arr.insert(2);
    // cout<<arr.length()<<endl;
    // for (int i = 0; i < arr.length(); i++)
    // {
    //     cout<<arr[i]<<" ";
    // }

    // for (int i = 1; i < n; i++)
    // {
    //     cin>>
    // }

    return 0;
}