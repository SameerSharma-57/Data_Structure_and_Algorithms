#include <iostream>
using namespace std;
typedef struct Node{
    float value;
    float weight;
    Node(){}
    Node(float w,float v):weight(w),value(v){}
}Node;
bool compare(Node *n1, Node *n2)
{
    if((float)(n1->value/n1->weight)>(float)(n2->value/n2->weight)){
        return true;
    }
    else if((float)(n1->value/n1->weight)==(float)(n2->value/n2->weight) && n1->weight>n2->weight){
        cout<<n1->weight<<" "<<n2->weight<<endl;
        return true;
    }
    return false;
}

int partition(Node *arr[], int start, int end)
{
    int i = start;
    int j = start;
    Node *temp;
    Node *pivot = arr[end];
    while (i < end)
    {
        if (compare(pivot, arr[i]))
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

void quicksort(Node *arr[], int high, int low = 0)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quicksort(arr, high, p + 1);
        quicksort(arr, p - 1, low);
    }
    return;
}
int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif  
    int n;
    cin>>n;
    Node * arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i]=new Node();
    }
    
    for (int i = 0; i < n; i++)
    {
        float w;
        cin>>w;
        arr[i]->weight=w;
    }
    for (int i = 0; i < n; i++)
    {
        float v;
        cin>>v;
        arr[i]->value=v;
    }
    
    quicksort(arr,n-1);
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<arr[i]->weight<<" "<<arr[i]->value<<endl;
    // }
    // cout<<endl;
    
    int capacity;
    cin>>capacity;
    float sum=0;
    float profit=0;
    int i=n-1;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]->weight<<" "<<arr[i]->value<<endl;
    }
    
    for ( i = n - 1; i >= 0; i--)
    {
        if(sum+arr[i]->weight>capacity){
            break;
        }
        sum+=arr[i]->weight;
        profit+=arr[i]->value;
    }
    if(i>=0){
    profit+=(capacity-sum)*(arr[i]->value/arr[i]->weight);

    }
    cout<<(int)profit;


    
    
    
    return 0;
}