#include <iostream>
using namespace std;

int BinarySearchRecursive(int arr[], int start, int end, int x)
{
    if (start <= end)
    {
        int middle = start + (end - start) / 2;
        if (arr[middle] == x)
        {
            return middle;
        }
        else if (arr[middle] > x)
        {
            cout<<middle<<" "<<end<<endl;
            return BinarySearchRecursive(arr, start, middle - 1, x);
        }
        cout<<start<<" "<<middle+1<<endl;

            return BinarySearchRecursive(arr, middle + 1, end, x);
        
    }
    return -1;
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
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr[i] = temp;
    }
    int x;
    cin >> x;
    cout<<BinarySearchRecursive(arr,0,n-1,x);

    return 0;
}