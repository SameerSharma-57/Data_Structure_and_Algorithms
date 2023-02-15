#include <iostream>
using namespace std;
#define int long long int
int max(int a,int b){
    return a>b?a:b;
}

int min(int a,int b){
    return a>b?b:a;
}

int solve(int i, int j, int arr[],int n,int* solved[])
{
    if(i>j || j>=n || i<0){
        return 0;
    }
    if(solved[i][j]!=0){
        return solved[i][j];
    }
    if(i==j){
        solved[i][i]=arr[i];
        return arr[i];
    }
    if(j==i+1){
        solved[i][j]=max(arr[i],arr[j]);
        return max(arr[i],arr[j]);
    }
    int choice1=arr[i]+min(solve(i+2,j,arr,n,solved),solve(i+1,j-1,arr,n,solved));
    int choice2=arr[j]+min(solve(i,j-2,arr,n,solved),solve(i+1,j-1,arr,n,solved));
    solved[i][j]=max(choice1,choice2);
    return solved[i][j];    
    
}

int maximumSum(int arr[],int n){
    int* solved[n];
    for (int i = 0; i < n; i++)
    {
        int * temp=new int[n];
        for (int j = 0; j < n; j++)
        {
            temp[j]=0;
        }
        solved[i]=temp;
        
    }
    return solve(0,n-1,arr,n,solved);
    
}

int32_t main()
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
    cout<<maximumSum(arr,n);
    
    return 0;
}