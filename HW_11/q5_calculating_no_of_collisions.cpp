#include <iostream>
using namespace std;

int hashFunction(int n,int x){
    return x%n;
}

int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n,m;
    cin>>n>>m;
    bool arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i]=0;
    }
    int count=0;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin>>x;
        int r=hashFunction(n,x);
        if(arr[r]){
            count++;
        }
        else{
            arr[r]=1;
        }
    }
    cout<<count;
    
    return 0;
}
