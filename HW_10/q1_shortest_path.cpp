#include <iostream>
// #include <climits>
using namespace std;
#define int long long int
#define INF 1e15
typedef struct Node
{

    int distance = INF;

    int visited = 0;
    Node() : distance(INF), visited(0) {}
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
// int findMinimum(Node* arr,int n){
//     int min=

// }

void dijkstraAlgo(Node *arr[], int n, int *graph[])
{
    arr[0]->distance = 0;
    int ind_arr[n];
    for (int i = 0; i < n; i++)
    {
        ind_arr[i] = i;
    }
    int temp = n;
    while (temp != 0)
    {
        int ind = ExtractMin(arr, ind_arr, temp);
        arr[ind]->visited = 1;
        for (int i = 0; i < n; i++)
        {
            if (graph[ind][i] != 0 && arr[i]->visited != 1)
            {
                if ((arr[ind]->distance + graph[ind][i]) < arr[i]->distance)
                {
                    arr[i]->distance = arr[ind]->distance + graph[ind][i];
                    // min_heapify(arr, ind_arr, i, temp);
                }
            }
        }
        Build_heap(arr,ind_arr,temp);
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
    int *graph[n];
    for (int i = 0; i < n; i++)
    {
        int *temp = new int[n];
        for (int j = 0; j < n; j++)
        {
            temp[j] = 0;
        }
        graph[i] = temp;
    }

    int x, y, w;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> w;
        graph[x - 1][y - 1] = w;
        graph[y - 1][x - 1] = w;
    }
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
        arr[i] = new Node();
    }
    dijkstraAlgo(arr, n, graph);
    for (int i = 0; i < n; i++)
    {
        if (arr[i]->distance == INF)
        {
            cout << "-1" << " ";
        }
        else
        {
            cout << arr[i]->distance << " ";
        }
    }
    cout << endl;

    return 0;
}