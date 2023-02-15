#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++)
    { 
        key = arr[i]; 
        j = i - 1; 
  
        // Move elements of arr[0..i-1],  
        // that are greater than key, to one 
        // position ahead of their 
        // current position
        while (j >= 0 && arr[j] > key)
        { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
} 
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
    // insertionSort(arr,n);
    int count=1;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    int temp;
    for (int i = 0; i < n; i++)
    {
        if(i==0){
            temp=arr[i];
        }
        else if(temp==arr[i]){
            count++;
        }
        else{
            temp=arr[i];
            count=1;
        }
        if(count==3){
            cout<<temp<<" ";
        }
        

    }
    


    
    return 0;
}