#include <iostream>
#include <vector>
using namespace std;
#define int long long int
int32_t main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int cases;
    cin >> cases;
    for (int _ = 0; _ < cases; _++)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = s[i] - '0';
        }
        int flag = 0;
        for (int v = 0; v < k; v++)
        {
            int ind = 0;
            while (ind < n)
            {
                if (arr[ind] == 1)
                {
                    flag = 0;

                    int left = ind - 1;
                    int right = ind + 1;
                    if (left >= 0 && arr[left] == 0)
                    {
                        arr[left] = 1;
                        flag = 0;
                    }
                    if (right < n && arr[right] == 0)
                    {
                        arr[right] = 1;
                        flag = 1;
                    }
                    arr[ind] = 0;
                    ind = ind + 1 + flag;
                }
                ind++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << arr[i];
        }
        cout << endl;
    }

    return 0;
}