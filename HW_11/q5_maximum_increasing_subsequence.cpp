#include <iostream>
using namespace std;

int max_in_array(int arr[],int n){
    int max=arr[0];
    for (int i = 0; i < n; i++)
    {
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
    
}

int LengthOfLongestIncreasingSubsequence(int arr[], int n)
{
    int length[n];
    length[0]=1;
    for (int i = 0; i < n; i++)
    {
        length[i]=1;
        for (int j = 0; j < i; j++)
        {
            if(arr[j]<arr[i] && length[i]<length[j]+1){
                length[i]=length[j]+1;

            }
        }
        
    }
    return max_in_array(length,n);
    

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
    cout<<LengthOfLongestIncreasingSubsequence(arr,n);

    return 0;
}