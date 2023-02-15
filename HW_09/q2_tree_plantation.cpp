#include <iostream>
using namespace std;

int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    int No_of_vertical_edges = n*(m-1);
    int No_of_horizontal_edges=m*(n-1);
    int Total_no_of_edges=No_of_horizontal_edges+No_of_vertical_edges;
    cout<<Total_no_of_edges<<endl;

    return 0;
}