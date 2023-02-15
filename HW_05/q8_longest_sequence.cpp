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

int lengthOfLongestSequence(int arr[],int n){
    int count=1;
    int max_count=1;
    int ind=1;
    while(ind<n){
        if((arr[ind]-arr[ind-1])==1){
            count+=1;
        }
        else{
            if(max_count<count){
                max_count=count;
            }
            count=1;
        }
        ind++;
    }
    if(max_count<count){
        max_count=count;
    }
    return max_count;
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
    quicksort(arr,n-1);
    cout<<lengthOfLongestSequence(arr,n)<<endl;
    

    return 0;
}