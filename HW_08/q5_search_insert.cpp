#include <iostream>
using namespace std;

int binarySearch(int arr[],int high,int low,int x){
    int mid=(low+high)/2;
    cout<<mid<<" ";
    if(low<=high){
        // int mid=(low+high)/2;
        if(arr[mid]==x){
            cout<<"mid is found"<<mid<<endl;
            return mid;
        }
        else if(arr[mid]<x){
            return binarySearch(arr,high,mid+1,x);
        }
        return binarySearch(arr,mid-1,low,x);
    }
    return (mid+1);

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
    for (int j = 0; j < n; j++)
    {
        cin>>arr[j];
    }
    int x;
    cin>>x;
    cout<<binarySearch(arr,n,0,x);
    return 0;
}