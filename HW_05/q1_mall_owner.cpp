#include <iostream>
using namespace std;

typedef struct Node
{
    int time, number;

    Node() {}

    Node(int val1, int val2) : time(val1), number(val2) {}

} Node;

bool compare(Node *n1, Node *n2)
{
    if (n1->time > n2->time)
    {
        return true;
    }
    else if (n1->time == n2->time && n2->number <= 0)
    {

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
    cin >> n;
    Node *arr[2 * n];
    int in_time, out_time, number;
    Node *nd;
    int ind = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> in_time >> out_time >> number;
        nd = new Node(in_time, number);
        arr[ind++] = nd;
        nd = new Node(out_time, -1 * number);
        arr[ind++] = nd;
    }
    quicksort(arr, 2 * n - 1, 0);
    int max = 0;
    int sum = 0;
    for (int i = 0; i < 2 * n - 1; i++)
    {
        sum += arr[i]->number;
        if (sum > max)
        {
            max = sum;
        }
    }
    cout << max << endl;
    return 0;
}