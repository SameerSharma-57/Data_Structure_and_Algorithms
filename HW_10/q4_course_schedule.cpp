#include <iostream>
using namespace std;
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
    Vector adj;
    char color;
    Node():adj(Vector(2)),color('w'){};
    
    

}Node;

bool detectCycle(Node* arr[],int n, int s){
    arr[s]->color='g';
    bool out=0;
    for (int i = 0; i < arr[s]->adj.size(); i++)
    {
        if(arr[arr[s]->adj[i]]->color=='g'){
            return 1;
        }
        else if(arr[arr[s]->adj[i]]->color=='w'){
            out=out||detectCycle(arr,n,arr[s]->adj[i]);
        }
       
    }
    arr[s]->color='b';
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
        int u,v;
        cin>>u>>v;
        // cout<<u<<v;
        arr[u-1]->adj.insert(v-1);
        // cout<<arr[u-1]->adj.Capacity()<<" ";
    }
    for (int i = 0; i < n; i++)
    {
        if(arr[i]->color=='w' && detectCycle(arr,n,i)){
            cout<<"No"<<endl;
            return 0;
        }

    }
    cout<<"Yes";
    
    

    return 0;
}