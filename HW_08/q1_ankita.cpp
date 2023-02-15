#include <iostream>
using namespace std;

int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n,x,y;
    cin>>n>>x>>y;
    int temp;
    int odd=0;
    int even=0;
    for (int i = 0; i < n; i++)
    {
        cin>>temp;
        if(temp%2==0){
            even++;
        }
        else{
            odd++;
        }
    }
    
    if(y%2==1 && x%2==0){
        cout<<"YES"<<endl;
    }
    else if(y%2==1 && x%2==1 && odd>0){
        cout<<"YES"<<endl;
    }
    else if(y%2==0 && x%2==1 && even>0){
        cout<<"YES"<<endl;
    }
    else if(y%2==0 && x%2==0){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}