#include <iostream>
#include <cmath>
using namespace std;
# define int long long int
int32_t main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int cases;
    cin >> cases;
    
    for (int i = 0; i < cases; i++)
    {
        string s;
        cin >> s;
        int count = 1;
        int t = 0;
        bool flag = 0;
        char temp = s[0];
        for (int j = 1; j < s.length(); j++)
        {
            if (s[j] != temp)
            {
                t++;
                flag = 1;
                temp=s[j];
            }
            else
            {
                flag = 0;
            }
            if (!flag && t!=0)
            {
                if(t%2){
                    int r=(t+1)/2;
                    count*=(pow(2,r)+pow(2,r-1)-1);
                }
                else{
                    int r=t/2;
                    count*=(pow(2,r)+pow(2,r)-1);
                }
                t=0;
            }
        }

        if ( t!=0)
            {
                if(t%2){
                    int r=(t+1)/2;
                    count*=(pow(2,r)+pow(2,r-1)-1);
                }
                else{
                    int r=t/2;
                    count*=(pow(2,r)+pow(2,r)-1);
                }
                t=0;
            }
        cout<<count%998244353<<endl;
    }
    return 0;
}
