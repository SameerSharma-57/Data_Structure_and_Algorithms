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
    Vector(int n = 1000000) : arr(new int[n]), capacity(n), curr_size(0) {}
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
    void update(int ind, int x)
    {
        arr[ind] = x;
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
    void update(int n, int w)
    {
        for (int i = 0; i < neighbour.size(); i++)
        {
            if (neighbour[i] == n)
            {
                weight.update(i, w);
            }
        }
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

void dijkstraAlgo(Node *arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i]->distance = INF;
        arr[i]->visited = 0;
    }
    int start = 0;

    arr[start]->distance = 0;

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
        // cout<<ind<<endl;
        // for (int i = 0; i < n; i++)
        // {
        //     cout<<arr[i]->distance<<" ";
        // }
        // cout<<endl;
        

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

    Node *arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new Node(n);
    }
    int x, y, w;
    int *temp[m];
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> w;
        arr[x - 1]->insert(y - 1, w);
        
        int *t = new int[3]{x - 1, y - 1, w};
        temp[i] = t;
    }
    
    

    int min = INF;
    for (int i = 0; i < m; i++)
    {
        arr[temp[i][0]]->update(temp[i][1], temp[i][2] / 2);
        // arr[temp[i][1]]->update(temp[i][0],temp[i][2]/2);
        dijkstraAlgo(arr, n);
        if (arr[n - 1]->distance < min)
        {
            min = arr[n - 1]->distance;
        }
        arr[temp[i][0]]->update(temp[i][1], temp[i][2]);
        // arr[temp[i][1]]->update(temp[i][0],temp[i][2]);
    }

    cout << min;

    return 0;
}