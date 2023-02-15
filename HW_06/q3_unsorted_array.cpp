#include <iostream>
using namespace std;
int LengthOfMinimumSubArray(int arr[], int n)
{
    int start=0;
    int end=n-1;
    while(arr[start]<=arr[start+1]&& start<n){
        start++;

    }
    if(start==n){
        return -1;
    }
    while(arr[end]>=arr[end-1]){
        end--;
    }
    int max=arr[start];
    int min=arr[end];
    for (int i = start; i <= end ;i++)
    {
        if(arr[i]>max){
            max=arr[i];
        }
        if(arr[i]<min){
            min=arr[i];
        }
    }
    while(arr[start-1]>min && start>0){
        start--;
    }
    while(arr[end+1]<max && end<n-1){
        end++;
    }
    return end-start+1;
    
}
int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<LengthOfMinimumSubArray(arr,n)<<endl;

    return 0;
}