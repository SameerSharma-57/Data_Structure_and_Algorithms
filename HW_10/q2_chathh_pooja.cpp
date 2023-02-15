#include <iostream>

using namespace std;
#define int long long int
#define INF 1e15

class Vector
{
    int *arr;
    int capacity = 1;
    int curr_size = 0;

public:
    Vector(int n = 1) : arr(new int[n]), capacity(n), curr_size(0) {}
    void insert(int x)
    {
        if (curr_size + 1 > capacity)
        {
            int *temp = new int[2 * capacity + 1];
            capacity = 2 * capacity + 1;
            for (int i = 0; i < curr_size; i++)
            {
                temp[i] = arr[i];
            }
            int *fre = arr;
            arr = temp;
            free(fre);
        }
        arr[curr_size++] = x;
    }
    int size()
    {
        return curr_size;
    }
    int operator[](int ind)
    {
        return arr[ind];
    }
    int Capacity()
    {
        return capacity;
    }
};
typedef struct Node
{

    int distance = INF;

    Vector neighbour;
    Vector weight;

    int visited = 0;
    Node(int n) : distance(INF), visited(0) {}
    void insert(int n, int w)
    {

        neighbour.insert(n);
        weight.insert(w);
    }

    // Node(string s, int f) : distance(f), visited(0) {}

} Node;

bool compare(Node *a, Node *b)
{
    if (a->distance > b->distance)
    {
        return true;
    }

    return false;
}

void min_heapify(Node *arr[], int ind_arr[], int ind, int n)
{
    int left = 2 * ind + 1;
    int right = 2 * ind + 2;

    int smallest = ind;
    if (left < n && compare(arr[ind_arr[smallest]], arr[ind_arr[left]]))
    {
        smallest = left;
    }
    if (right < n && compare(arr[ind_arr[smallest]], arr[ind_arr[right]]))
    {
        smallest = right;
    }
    // cout<<smallest<<" ";
    if (smallest != ind)
    {
        int temp = ind_arr[ind];
        ind_arr[ind] = ind_arr[smallest];
        ind_arr[smallest] = temp;
        return min_heapify(arr, ind_arr, smallest, n);
    }
    // cout<<"return"<<" ";
    return;
}
void Build_heap(Node *arr[], int ind_arr[], int n)
{
    for (int i = (int)n / 2 + 1; i >= 0; i--)
    {
        min_heapify(arr, ind_arr, i, n);
    }
}

int ExtractMin(Node *arr[], int ind_arr[], int &n)
{
    int temp = ind_arr[0];
    ind_arr[0] = ind_arr[n - 1];
    n--;
    min_heapify(arr, ind_arr, 0, n);
    return temp;
}

void dijkstraAlgo(Node *arr[], int n, int special[], int k)
{
    for (int i = 0; i < n; i++)
    {
        arr[i]->distance = INF;
        arr[i]->visited = 0;
    }
    int start = special[0] - 1;

    for (int i = 0; i < k; i++)
    {
        arr[special[i] - 1]->distance = 0;
    }

    int ind_arr[n];
    for (int i = 0; i < n; i++)
    {
        ind_arr[i] = i;
    }
    int temp = n;
    Build_heap(arr, ind_arr, temp);
    while (temp != 0)
    {
        int ind = ExtractMin(arr, ind_arr, temp);

        arr[ind]->visited = 1;
        for (int i = 0; i < arr[ind]->neighbour.size(); i++)
        {
            if (arr[arr[ind]->neighbour[i]]->visited != 1)
            {

                if ((arr[ind]->distance + arr[ind]->weight[i]) < arr[arr[ind]->neighbour[i]]->distance)
                {
                    arr[arr[ind]->neighbour[i]]->distance = arr[ind]->distance + arr[ind]->weight[i];
                    // min_heapify(arr, ind_arr, i, temp);
                }
            }
        }
        Build_heap(arr, ind_arr, temp);
    }
}

int32_t main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    // int *graph[n];
    // for (int i = 0; i < n; i++)
    // {
    //     int *temp = new int[n];
    //     for (int j = 0; j < n; j++)
    //     {
    //         temp[j] = 0;
    //     }
    //     graph[i] = temp;
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout<< graph[i][j]<<" ";
    //     }
    //     cout<<endl;

    // }
    Node *arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new Node(n);
    }
    int x, y, w;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> w;
        arr[x - 1]->insert(y - 1, w);
        arr[y - 1]->insert(x - 1, w);
    }

    int k;
    cin >> k;
    int special[k];
    for (int i = 0; i < k; i++)
    {
        cin >> special[i];
    }

    // for (int i = 0; i < k; i++)
    // {
    //     cout<<special[i]<<" ";
    // }

    int q;
    cin >> q;
    dijkstraAlgo(arr, n, special, k);
    int total = 0;
    for (int i = 0; i < q; i++)
    {
        int s;
        cin >> s;
        if (arr[s - 1]->distance == INF)
        {
            total += -1;
        }
        else
        {
            total += arr[s - 1]->distance;
        }
    }
    cout << total;
    // Vector v;
    // v.insert(3);
    // v.insert(7);
    // v.insert(13);
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout<<v[i]<<" ";
    // }
    // cout<<v.size()<<" "<<v.Capacity();
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < arr[i]->adj.size(); j++)
    //     {
    //         cout<<arr[i]->adj[j].first<<" "<<arr[i]->adj[j].second<<'\t';
    //     }
    //     cout<<endl;

    // }

    return 0;
}