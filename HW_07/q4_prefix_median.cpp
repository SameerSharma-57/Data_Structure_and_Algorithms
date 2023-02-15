#include <iostream>
using namespace std;

void median(int arr[], int n)
{
    int val = arr[n - 1];
    int ind = n - 2;
    while (arr[ind] > val && ind >= 0)
    {
        arr[ind + 1] = arr[ind];
        ind--;
    }
    arr[ind + 1] = val;
}

int median(int arr[],int n){
    int temp=(n-1)/2;
    return arr[temp];
}
int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    // int arr[]={2,5,6,7,1};
    // insertion_sort(arr,5);
    // for (int i = 0; i < 5; i++)
    // {
    //     cout<<arr[i]<<endl;
    // }
    int arr[n];
    int ind = 0;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr[ind++] = temp;
        median(arr, ind);
        cout<<median(arr,ind)<<" ";
    }

    return 0;
}