#include <iostream>
using namespace std;

void countSort(int assgn[],int grade[],int n){
    int min = assgn[0];
    int max = assgn[0];
    for (int i = 0; i < n; i++)
    {
        if (assgn[i] < min)
        {
            min = assgn[i];
        }
        if (assgn[i] > max)
        {
            max = assgn[i];
        }
    }
    int count[max - min + 1];
    for (int i = 0; i < max - min + 1; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        count[assgn[i] - min] += 1;
    }
    for (int i = 1; i < max - min + 1; i++)
    {
        count[i] = count[i] + count[i - 1];
    }

    int assgn_out[n];
    int grade_out[n];
    for (int i = n-1; i >=0; i--)
    {
        assgn_out[count[assgn[i] - min] - 1] = assgn[i];
        grade_out[count[assgn[i]-min]-1]=grade[i];
        count[assgn[i] - min] -= 1;
    }
    for (int i = 0; i <n; i++)
    {
        assgn[i]=assgn_out[i];
        grade[i]=grade_out[i];
    }
    
}
int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n,r,a;
    cin>>n>>r>>a;
    int grade[n];
    int assignment[n];
    int currSum=0;
    int g,ag;
    for (int i = 0; i < n; i++)
    {
        cin>>g>>ag;
        grade[i]=g;
        assignment[i]=ag;
        currSum+=g;
    }
    countSort(assignment,grade,n);
    for (int i = 0; i < n; i++)
    {
        cout<<grade[i]<<" "<<assignment[i]<<endl;
    }
    
    
    int ind=0;
    int noOfAssignments=0;
    
    while(currSum<r*a && ind<n){
        if(grade[ind]>=r){
            ind++;
        }
        else{
            grade[ind]+=1;
            currSum+=1;
            noOfAssignments+=assignment[ind];

        }


    }
    cout<<noOfAssignments<<endl;

    return 0;
}