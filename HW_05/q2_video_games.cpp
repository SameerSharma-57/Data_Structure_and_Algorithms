#include <iostream>
using namespace std;

int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n,q;
    cin>>n>>q;
    int arr[n];
    int sum=0;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin>>temp;
        sum+=temp;
        arr[i]=sum;
        /* code */
    }
    for (int i = 0; i < q; i++)
    {
        cin>>temp;
        if(temp>=sum){
            cout<<n<<" ";
        }
        else{
            int ind=0;
            while(arr[ind]<=temp){
                ind++;
            }
            cout<<ind<<" ";
            
        }
    }
    
    
    
    return 0;
}