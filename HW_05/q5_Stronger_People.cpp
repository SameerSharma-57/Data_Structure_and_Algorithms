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

int median(int arr[], int n)
{
    int out;
    if(n==0){
        out=0;
    }
    if (n % 2 == 0)
    {
        out = (arr[(n / 2) - 1] + arr[n / 2]) / 2;
    }
    else
    {
        out = arr[(n - 1) / 2];
    }
    return out;
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
    
    
    int k;
    cin >> k;
    int out[k];
    int md = median(arr, n);
    
    int l = 0;
    int r = n - 1;
    int ind = 0;
    while (l <= r && ind < k)
    {
        if ((md - arr[l]) >= (arr[r] - md))
        {
            
            out[ind] = arr[l];
            l++;
        }
        else
        {
            
            out[ind] = arr[r];
            r--;
        }
        ind++;
    }
    quicksort(out,ind-1);
    for (int i = 0; i < ind; i++)
    {
        cout<<out[i]<<" ";
    }
    

    return 0;
}