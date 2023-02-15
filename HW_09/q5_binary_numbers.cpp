#include <iostream>
using namespace std;

#define INT_MAX 1000
template <class T>
class Queue
{
public:
    T arr[INT_MAX];
    int _back = -1;
    int _front = 0;
    int currSize = 0;

    bool empty()
    {
        if (currSize > 0)
        {
            return 0;
        }
        return 1;
    }
    void push(T x)
    {
        if (currSize <= INT_MAX)
        {
            _back++;
            if (_back >= INT_MAX)
            {
                _back = 0;
            }
            arr[_back] = x;
            currSize++;
            return;
        }
        cout << "overflow" << endl;
    }

    void pop()
    {
        if (!this->empty())
        {
            currSize--;
            _front++;
            return;
        }
        cout << "queue is empty" << endl;
        return;
    }

    T front()
    {

        return arr[_front];
    }

    T back()
    {
        return arr[_back];
    }

    int size()
    {
        return currSize;
    }
};

int mod(int n,string s){
    int r=0;
    for (int i = 0; i<s.length(); i++)
    {
        r=10*r+(s[i]-'0')%n;
        r=r%n;
    }
    return r;
    
}

string getMinimumBinaryMultiple(int n,bool visited[])
{
    string s="1";
    Queue<string> q;
    q.push(s);
    while(!q.empty()){
        string u=q.front();
        q.pop();
        int r=mod(n,u);
        if(r==0){
            return u;
        }
        else if(!visited[r]){
            visited[r]=1;
            q.push(u+"0");
            q.push(u+"1");
        }
        
    }
    return "error";


}
int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    if(n==0){
        cout<<0<<endl;
        return 0;
    }
    bool visited[n]={0};
    cout<<getMinimumBinaryMultiple(n,visited)<<endl;

    return 0;
}