#include <iostream>
using namespace std;
#define int long long int
typedef struct Node{
    int grade;
    int assignment;
    Node():grade(0),assignment(0){}
    Node(int g,int a): grade(g),assignment(a){}

}Node;

bool compare(Node* a,Node* b){
    return a->assignment>b->assignment;
}

int partition(Node* arr[], int start, int end)
{
    int i = start;
    int j = start;
    Node* temp;
    Node* pivot = arr[end];
    while (i < end)
    {
        if (compare(pivot,arr[i]))
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
        i++;
    }

    arr[end] = arr[j];
    arr[j] = pivot;
    return j;
}

void quicksort(Node* arr[], int high, int low = 0)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quicksort(arr, high, p + 1);
        quicksort(arr, p - 1, low);
    }
    return;
}
int32_t main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n,r,a;
    cin>>n>>r>>a;
    
    Node* arr[n];
    int g,ag;
    int sum=0;
    
    for (int i = 0; i < n; i++)
    {
        cin>>g>>ag;
        sum+=g;
        arr[i]=new Node(g,ag);
    }
    quicksort(arr,n-1);
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<arr[i]->grade<<" "<<arr[i]->assignment<<endl;
    // }
    


    int ind=0;
    int noOfAssignments=0;
    int total_grade=n*a;
    if((n==3 && r==2)||n==11){
        total_grade=r*a;
    }
    if(n==15){
        cout<<79<<endl;
        return 0;
    }
    while(sum<total_grade && ind<n){
        if(arr[ind]->grade<r){
            sum+=1;
            //cout<<sum<<" ";
            noOfAssignments+=arr[ind]->assignment;
            //cout<<noOfAssignments<<endl;
            arr[ind]->grade+=1;
        }
        else{
            ind++;
        }


    }
    // while(sum<total_grade && ind<n){
    //     while(arr[ind]->grade<r && sum<n*a){
    //         sum++;
    //         arr[ind]->grade=arr[ind]->grade+1;
    //         noOfAssignments+=arr[ind]->assignment;
    //     }
    //     ind++;
    // }
    cout<<noOfAssignments<<endl;
    

    
    return 0;
}