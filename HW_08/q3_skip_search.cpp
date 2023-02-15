#include <iostream>
using namespace std;

int skip_search(int arr[],int n,int x){
    int ind=0;
    while(ind<n&&arr[ind]<x){
        ind+=2;
    }
    if(arr[n-1]==x){
        return n-1;
    }
    else if(arr[ind]==x){
        return ind;
    }
    else if(arr[ind-1]==x){
        return ind-1;
    }
    return -1;


}
int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int x;
    cin>>x;
    cout<<skip_search(arr,n,x);

    
    return 0;
}