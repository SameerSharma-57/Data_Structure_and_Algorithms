#include <iostream>
using namespace std;

// void min_heapify(int arr[], int ind, int n)
// {
//     int left = 2 * ind + 1;
//     int right = 2 * ind + 2;

//     int smallest = ind;
//     if (left < n && arr[smallest] > arr[left])
//     {
//         smallest = left;
//     }
//     if (right < n && arr[smallest] > arr[right])
//     {
//         smallest = right;
//     }
//     // cout<<smallest<<" ";
//     if (smallest != ind)
//     {
//         int temp = arr[ind];
//         arr[ind] = arr[smallest];
//         arr[smallest] = temp;
//         return min_heapify(arr, smallest, n);
//     }
//     // cout<<"return"<<" ";
//     return;
// }
// void max_heapify(int arr[], int ind, int n)
// {
//     int left = 2 * ind + 1;
//     int right = 2 * ind + 2;

//     int smallest = ind;
//     if (left < n && arr[smallest] < arr[left])
//     {
//         smallest = left;
//     }
//     if (right < n && arr[smallest] < arr[right])
//     {
//         smallest = right;
//     }
//     // cout<<smallest<<" ";
//     if (smallest != ind)
//     {
//         int temp = arr[ind];
//         arr[ind] = arr[smallest];
//         arr[smallest] = temp;
//         return max_heapify(arr, smallest, n);
//     }
//     // cout<<"return"<<" ";
//     return;
// }

void max_heapify(int arr[], int ind, int n)
{
    if (ind <= 0 || ind >= n)
    {
        return;
    }
    int parent = (ind - 1) / 2;
    if (arr[parent] <= arr[ind])
    {
        int temp = arr[parent];
        arr[parent] = arr[ind];
        arr[ind] = temp;
        return max_heapify(arr, parent, n);
    }
    return;
}
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
    int temp=(n-1)/2;
    cout<< arr[temp]<<" ";
}
void min_heapify(int arr[], int ind, int n)
{
    if (ind <= 0 || ind >= n)
    {
        return;
    }
    int parent = (ind - 1) / 2;

    if (arr[parent] >= arr[ind])
    {
        int temp = arr[parent];
        arr[parent] = arr[ind];
        arr[ind] = temp;
        return min_heapify(arr, parent, n);
    }
    return;
}
int delete_root_in_max_heap(int arr[], int &n)
{
    // int temp = arr[n - 1];
    // n = n - 1;
    // int out=arr[0];
    // arr[0] = temp;
    // max_heapify(arr, 0, n);
    // return out;
    int out = arr[0];
    n = n - 1;
    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }
    if (n > 1)
    {
        if (arr[0] < arr[1])
        {
            int temp = arr[0];
            arr[0] = arr[1];
            arr[1]=temp;
        }
    }
    return out;
}
int delete_root_in_min_heap(int arr[], int &n)
{
    // int temp = arr[n - 1];
    // n = n - 1;
    // int out=arr[0];
    // arr[0] = temp;
    // min_heapify(arr, 0, n);
    // return out;
    int out = arr[0];
    n = n - 1;
    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }
     if (n > 1)
    {
        if (arr[0] > arr[1])
        {
            int temp = arr[0];
            arr[0] = arr[1];
            arr[1]=temp;
        }
    }
    return out;
}
// void Build_heap(int arr[], int n)
// {
//     for (int i = (int)n / 2 + 1; i >= 0; i--)
//     {
//         min_heapify(arr, i, n);
//     }
// }
int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // int arr[]={1,2,3,4,5};
    // maxi(arr,3,5);
    // for (int i = 0; i < 5; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }

    int n;
    cin >> n;
    int heapMax[n / 2 + 1];
    int heapMin[n / 2 + 1];
    int arr[n];
    int max_heap_size = 0;
    int min_heap_size = 0;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr[i]=temp;
        // if (i == 0)
        // {
        //     heapMax[max_heap_size++] = temp;
        //     // for (int j = 0; j < max_heap_size; j++)
        //     // {
        //     //     cout << heapMax[j] << " ";
        //     // }
        //     // cout << "max heap" << endl;
        // }
        // else
        // {
            if (temp <= heapMax[0])
            {
                heapMax[max_heap_size++] = temp;
                max_heapify(heapMax, max_heap_size - 1, max_heap_size);
            }
            else
            {
                heapMin[min_heap_size++] = temp;
                min_heapify(heapMin, min_heap_size - 1, min_heap_size);
            }
            median(arr,i+1);
            if (max_heap_size < min_heap_size)
            {
                // for (int j = 0; j < min_heap_size; j++)
                // {
                //     cout << heapMin[j] << " ";
                // }
                // cout << "root in min heap to be deleted" << endl;
                heapMax[max_heap_size++] = delete_root_in_min_heap(heapMin, min_heap_size);
                max_heapify(heapMax, max_heap_size - 1, max_heap_size);
                // min_heapify(heapMin, 1, min_heap_size);
            }
            if (max_heap_size > min_heap_size + 1)
            {
                // for (int j = 0; j < max_heap_size; j++)
                // {
                //     cout << heapMax[j] << " ";
                // }
                // cout << "root in max heap to be deleted" << endl;

                heapMin[min_heap_size++] = delete_root_in_max_heap(heapMax, max_heap_size);
                min_heapify(heapMin, min_heap_size - 1, min_heap_size);
                // max_heapify(heapMax, 1, max_heap_size);
            }
            // for (int j = 0; j < min_heap_size; j++)
            // {
            //     cout << heapMin[j] << " ";
            // }
            // cout << "min heap" << endl;
            // for (int j = 0; j < max_heap_size; j++)
            // {
            //     cout << heapMax[j] << " ";
            // }
            // cout << "max heap" << endl;
        // }
        // cout << heapMax[0] << " ";
    }

    // max_heapify(arr,0,5);
    // delete_root_in_min_heap(arr, n);
    // // cout<<arr[0]<<endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // int arr[]={2};
    // int n=1;
    // min_heapify(arr,1,n);
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    

    return 0;
}