#include <iostream>
using namespace std;
#define int long long int
int max(int a,int b){
    return a>b?a:b;
}

int min(int a,int b){
    return a>b?b:a;
}

int solve(int i, int j, string s,int n,int* solved[])
{
    if(i>j||j>=n||i<0){
        return 0;
    }
    if(solved[i][j]!=0){
        return solved[i][j];
    }
    if(i==j){
        solved[i][j]=1;
        return 1;
    }
    if(s[i]!=s[j]){
        // cout<<i<<" "<<j<<endl;
        solved[i][j]=max(solve(i+1,j,s,n,solved),solve(i,j-1,s,n,solved));
        return solved[i][j];
    }
    if(j==i+1){
        return 2;
    }
    solved[i][j]=solve(i+1,j-1,s,n,solved)+2;
    return solved[i][j];
    
}

int maximumLengthPalindrome(string s,int n){
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
    return solve(0,n-1,s,n,solved);
    
}

int32_t main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s;
    cin>>s;
    int n=s.length();
    cout<<maximumLengthPalindrome(s,n);
    
    return 0;
}