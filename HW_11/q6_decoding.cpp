#include <iostream>
using namespace std;

int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s;
    cin>>s;
    int ind=0;
    string temp="";
    int n=0;
    string out="";
    while(ind<s.length()){
        while(s[ind]!='['){
            temp+=s[ind];
            ind++;
        }
        n=stoi(temp);
        temp="";
        ind++;
        while(s[ind]!=']'){
            temp+=s[ind];
            ind++;
        }
        ind++;
        for (int i = 0; i < n; i++)
        {
            out+=temp;
        }
        temp="";
        



    }
    cout<<out;
    return 0;
}