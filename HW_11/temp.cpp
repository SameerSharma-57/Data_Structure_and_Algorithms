#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cmath>
#define int long long int
using namespace std;
int index(int arr[])
{
    int ind = 0;
    while (arr[ind] == 1)
    {
        ind++;
    }
    return ind;
}

void solve()
{
    int n;
    cin>>n;
    int arr[n];
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    bool together_n1=0;
    bool n1_1=0;
    for (int i = 0; i < n-1; i++)
    {
        if(arr[i]==-1 && arr[i+1]==-1){
            together_n1=1;
            break;
        }
        else if(arr[i]*arr[i+1]==-1){
            n1_1=1;
        }
    }
    if(together_n1){
        cout<<sum+4<<endl;
        return;
    }
    else if(n1_1){
        cout<<sum<<endl;
        return;
    }
    cout<<sum-4<<endl;
    
    
}

int32_t main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++)
    {
        solve();
    }
    // cout<<myfunc(2);

    // your code goes here
    return 0;
}
