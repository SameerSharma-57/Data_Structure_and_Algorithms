#include <iostream>
using namespace std;
int partition(int arr[], int start, int end)
{
    int i = start;
    int j = start;
    int temp;
    int pivot = arr[end];
    while (i < end)
    {
        if (pivot > arr[i])
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
        i++;
    }

    arr[end] = arr[j];
    arr[j] = pivot;
    return j;
}

void quicksort(int arr[], int high, int low = 0)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quicksort(arr, high, p + 1);
        quicksort(arr, p - 1, low);
    }
    return;
}
int MEX(int arr[],int n){
    int j=0;
    while(arr[j]<0){
        j++;
        if(j>=n){
            return 0;
        }
    }
    for (int i = j; i < n; i++)
    {
        if(arr[i]!=(i-j)){
            return (i-j);
        }
    }
    return (n-j);
    
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
    quicksort(arr, n - 1);
    cout<<MEX(arr,n);
    return 0;
}