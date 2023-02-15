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

int minNoOfGondola(int arr[], int n, int max_weight)
{
    int l = 0;
    int r = n - 1;
    int minGondola = 0;
    while (l <= r)
    {
        if (arr[l] + arr[r] <= max_weight)
        {
            minGondola += 1;
            l++;
            r--;
        }
        else{
            minGondola+=1;
            r--;
        }

    }
    return minGondola;

}
int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n,max_weight;
    cin>>n>>max_weight;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    quicksort(arr,n-1);
    cout<<minNoOfGondola(arr,n,max_weight)<<endl;
    

    return 0;
}