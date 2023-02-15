#include <iostream>
using namespace std;

void count_sort(int arr[],int n){
    int min = arr[0];
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    int count[max - min + 1];
    for (int i = 0; i < max - min + 1; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        count[arr[i] - min] += 1;
    }
    for (int i = 1; i < max - min + 1; i++)
    {
        count[i] = count[i] + count[i - 1];
    }

    int out[n];
    for (int i = 0; i < n; i++)
    {
        out[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min] -= 1;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i]=out[i];
    }
    

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
    count_sort(arr,n);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int curr;
    cin>>curr;
    string s;
    cin>>s;
    if(s=="UP"){
        int ind=0;
        while(arr[ind]<curr){
            ind++;
        }
        for (int i = ind; i < n; i++)
        {
            cout<<arr[i]<<" ";
        }
        for (int i = ind-1; i >=0; i--)
        {
            cout<<arr[i]<<" ";
        }
        
        
        
    }
    else{
        int ind=n-1;
        while(arr[ind]>curr){
            ind--;
        }
        for (int i = ind; i >=0; i--)
        {
            cout<<arr[i]<<" ";
        }
        for (int i = ind+1; i < n; i++)
        {
            cout<<arr[i]<<" ";
        }

    }
    

    
    return 0;
}