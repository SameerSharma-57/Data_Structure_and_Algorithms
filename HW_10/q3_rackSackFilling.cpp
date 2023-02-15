#include <iostream>
using namespace std;



int max(int a,int b){
    return a>b?a:b;
}

int ruckSack(int weight[],int value[],int n,int capacity){
    int graph[n+1][capacity+1];
    for (int i = 0; i < n+1; i++)
    {
        for (int w = 0; w < capacity+1; w++)
        {
            if(i==0||w==0){
                graph[i][w]=0;
            }
            else if(weight[i-1]<=w){
                graph[i][w]=max(graph[i-1][w],value[i-1]+graph[i-1][w-weight[i-1]]);
            }
            else{
                graph[i][w]=graph[i-1][w];
            }

        }
        
    }
    // for (int i = 0; i < capacity+1; i++)
    // {
    //     cout<<i<<'\t';
    // }
    // cout<<endl;
    
    // for (int i = 0; i < n+1; i++)
    // {
    //     for (int j = 0; j < capacity+1; j++)
    //     {
    //         cout<<graph[i][j]<<"\t";
    //     }
    //     cout<<endl;
        
    // }
    
    return graph[n][capacity];
    


}
int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin>>n;
    int weight[n];
    int value[n];
    for (int i = 0; i < n; i++)
    {
        cin>>weight[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>value[i];
    }
    int capacity;
    cin>>capacity;
    // cout<<n<<" "<<capacity;
    cout<<ruckSack(weight,value,n,capacity);
    
    

    return 0;
}