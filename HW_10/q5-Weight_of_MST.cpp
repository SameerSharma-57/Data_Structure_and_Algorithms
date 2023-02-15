#include <iostream>
using namespace std;
#define INF 1e8
class Vector
{
    int *arr;
    int capacity = 1;
    int curr_size = 0;

public:
    Vector(int n = 2) : arr(new int[n]), capacity(n), curr_size(0) {}
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
typedef struct Node{
    int key;
    int visited;
    Vector neighbour;
    Vector weight;
    Node():key(INF),visited(0){}
    void insert(int x,int y){
        neighbour.insert(x);
        weight.insert(y);
    }
}Node;

int findMin(Node* arr[],int n){
    int minKey=INF;
    int minInd;
    bool visit=1;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]->visited<visit){
            visit=arr[i]->visited;
            minKey=arr[i]->key;
            minInd=i;
        }
        else if( arr[i]->visited=visit&& minKey>=arr[i]->key){
            minKey=arr[i]->key;
            minInd=i;

        }
    }
    return minInd;
    
}
//assuming that here the graph is connected
int findMSTWeight(Node * arr[],int n){
    for (int i = 0; i < n; i++)
    {
        arr[i]->key=INF;
        arr[i]->visited=0;

    }
    arr[0]->key=0;
    int out=0;
    for (int i = 0; i < n; i++)
    {
        int ind=findMin(arr,n);
        out+=arr[ind]->key;
        arr[ind]->visited=1;
        for (int j = 0; j < arr[ind]->neighbour.size(); j++)
        {
            if(arr[(arr[ind]->neighbour[j])]->visited==0 && (arr[(arr[ind]->neighbour[j])]->key)>(arr[ind]->weight[j])){
                arr[(arr[ind]->neighbour[j])]->key=arr[ind]->weight[j];
            }
        }
        
    }
    return out;
    
    
    

}

int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n,m;
    cin>>n>>m;
    
    Node* arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i]=new Node();
    }
    for (int i = 0; i < m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        arr[u-1]->insert(v-1,w);
        arr[v-1]->insert(u-1,w);
    }
    cout<<findMSTWeight(arr,n);
    
    
    return 0;
}