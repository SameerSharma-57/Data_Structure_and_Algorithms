#include <iostream>
using namespace std;


int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n,k;
    cin>>n>>k;
    
    
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i]=0;
    }
    
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    int temp;
    for (int i = 0; i < n; i++)
    {
       
        cin>>temp;
        arr[temp%n]+=1;

    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;

    int out=0;
    k=k%n;
    for (int i = 0; i < n; i++)
    {
        // cout<<i<<" ";
        int r=n-((k*i)%n);
        if(r>=n){
            r=0;
        }
        // cout<<r<<" ";
        out+=arr[i]*arr[r];
        // cout<<out<<endl;
    }
    cout<<out;
    

    
    return 0;
}