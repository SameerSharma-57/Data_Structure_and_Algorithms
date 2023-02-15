// 
#include <iostream>
// # include <stdlib.h>
#include <bits/stdc++.h> 
using namespace std;
# define int long long int
// int partition(int arr[], int start, int end)
// {
//     int i = start;
//     int j = start;
//     int temp;
//     int pivot = arr[end];
//     while (i < end)
//     {
//         if (pivot > arr[i])
//         {
//             temp = arr[i];
//             arr[i] = arr[j];
//             arr[j] = temp;
//             j++;
//         }
//         i++;
//     }
    

//     arr[end] = arr[j];
//     arr[j] = pivot;
//     return j;
// }

// void quicksort(int arr[], int high, int low = 0)
// {
//     if (low < high)
//     {
//         int p = partition(arr, low, high);
//         quicksort(arr, high, p + 1);
//         quicksort(arr, p - 1, low);
//     }
//     return;
// }
int32_t main()
{
// #ifndef ONLINE_MODE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    int cases;
    cin >> cases;
    for (int _ = 0; _ < cases; _++)
    {
        int n;
        cin>>n;
        int arr[n];
        if (n <= 0)
        {
            cout << 0 << endl;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                cin >> arr[i];
            }
            // quicksort(arr, n - 1);
            sort(arr,arr+n);
            
            int max = 1;
            int count = 1;
            int temp = arr[0];
            for (int i = 1; i < n; i++)
            {
                if (arr[i] == temp)
                {
                    count++;
                }
                else
                {
                    temp = arr[i];
                    if (count > max)
                    {
                        max = count;
                    }
                    count = 1;
                }
            }
            if(count>max){
                max=count;
            }
            int out=log2(max);
            if((float)out==log2(max)){
                cout<<out<<endl;
            }
            else{
                cout<<out+1<<endl;
            }
        }
    }

    return 0;
}