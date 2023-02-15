#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#define int long long int
using namespace std;

long long calculate(long long p,
                    long long q)
{
    long long mod = 998244353, expo;
    expo = mod - 2;
 
    // Loop to find the value
    // until the expo is not zero
    while (expo) {
 
        // Multiply p with q
        // if expo is odd
        if (expo & 1) {
            p = (p * q) % mod;
        }
        q = (q * q) % mod;
 
        // Reduce the value of
        // expo by 2
        expo >>= 1;
    }
    return p;
}

int32_t main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++)
    {
        cout<<__gcd(6,1)<<endl;
        
        
        
        

        
    }

    // your code goes here
    return 0;
}
