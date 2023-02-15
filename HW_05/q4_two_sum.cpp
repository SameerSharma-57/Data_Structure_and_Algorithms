#include <iostream>
using namespace std;
int partition(int arr[],int start,int end){
    int i=start;
    int j=start;
    int temp;
    int pivot=arr[end];
    while(i<end){
        if(pivot>arr[i]){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            j++;
        }
        i++;
    }
    
    arr[end]=arr[j];
    arr[j]=pivot;
    return j;
    
}

void quicksort(int arr[],int high,int low=0){
    if(low<high){
        int p=partition(arr,low,high);
        quicksort(arr,high,p+1);
        quicksort(arr,p-1,low);
    }
    return ;

}
int twoSum(int arr[],int n, int val){
    int left=0;
    int right=n-1;
    while(left<right){
        if(arr[left]+arr[right]==val){
            return 1;
        }
        else if(arr[left]+arr[right]<val){
            left++;
        }
        else{
            right--;
        }
    }
    return 0;
}
int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n,k;
    cin>>n>>k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    quicksort(arr,n-1);
    cout<<twoSum(arr,n,k)<<endl;
    
    return 0;
}