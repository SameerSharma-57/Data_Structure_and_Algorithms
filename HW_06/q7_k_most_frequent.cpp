#include <iostream>
#include <unordered_map>
# include <string>
using namespace std;

typedef struct Node
{
    string data;
    int frequency;
    int index = 0;
    Node() : data(""), frequency(0), index(0) {}
    Node(string s, int f, int i) : data(s), frequency(f), index(i) {}

} Node;

string toLower(string s){
    string out="";
    
    for (int i = 0; i < s.length(); i++)
    {
        if('A'<=s[i] && s[i]<='Z'){
            int r=s[i];
            r+=32;
            s[i]=(char) r;
        }
    }
    return s;
    

}

bool compare(Node *a, Node *b)
{
    if (a->frequency > b->frequency)
    {
        return true;
    }
    else if (a->frequency == b->frequency && toLower(a->data) < toLower(b->data))
    {
        return true;
    }
    return false;
}

void min_heapify(Node *arr[], int ind, int n)
{
    int left = 2 * ind + 1;
    int right = 2 * ind + 2;

    int smallest = ind;
    if (left < n && compare(arr[smallest], arr[left]))
    {
        smallest = left;
    }
    if (right < n && compare(arr[smallest], arr[right]))
    {
        smallest = right;
    }
    // cout<<smallest<<" ";
    if (smallest != ind)
    {
        Node *temp = arr[ind];
        arr[ind] = arr[smallest];
        arr[smallest] = temp;
        return min_heapify(arr, smallest, n);
    }
    // cout<<"return"<<" ";
    return;
}
void Build_heap(Node *arr[], int n)
{
    for (int i = (int)n / 2 + 1; i >= 0; i--)
    {
        min_heapify(arr, i, n);
    }
}

int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string s;
    getline(cin, s);
    int k ;
    cin >> k;
    string temp = "";
    unordered_map<string, int> m;
    unordered_map<string, int> index_mp;
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] == ' ' || i == s.length() - 1) && temp != "")
        {
            if (m.find(temp) == m.end())
            {
                m[temp] = 1;
                index_mp[temp] = i;
            }
            else
            {
                m[temp] += 1;
            }
            temp = "";
        }
        else if (('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z'))
        {
            temp += s[i];
        }
    }
    if (temp != "")
    {
        if (m.find(temp) == m.end())
        {
            m[temp] = 1;
            index_mp[temp] = s.length();
        }
        else
        {
            m[temp] += 1;
        }
    }
    // std::unordered_map<string,int> iterator itr;
  
        auto itr = m.begin();
        int ind = 0;
        Node *arr[k];
        while (ind < k && itr != m.end())
        {
            arr[ind] = new Node(itr->first, itr->second, index_mp[itr->first]);
            ind++;
            itr++;
        }
        if (itr == m.end() && ind != k)
        {
            cout << -1 << endl;
            return 0;
        }
        Build_heap(arr, k);
        Node *tmp;
        while (itr != m.end())
        {
            tmp = new Node(itr->first, itr->second, index_mp[itr->first]);
            if (compare(tmp, arr[0]))
            {
                arr[0] = tmp;
                min_heapify(arr, 0, k);
            }
            itr++;
        }
        cout << arr[0]->data << endl;
    
    // string sam="SAMEER";
    // cout<<toLower(sam)<<endl;

    // arr[0]=new Node("sameer",7);
    // arr[1]=new Node("sharma",4);
    // arr[2]=new Node("purvika",10);
    // arr[3]=new Node("shimla",5);
    // arr[4]=new Node("sameer",2);
    // //min_heapify(arr,0,5);
    // // for (int i = 0; i < 4; i++)
    // // {
    // //     cout<<arr[i]->data<<" "<<arr[i]->frequency<<endl;
    // // }
    // // cout<<endl;
    // // min_heapify(arr,1,4);

    // int n;
    // cin>>n;
    // Node* arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     int temp;
    //     cin>>temp;
    //     arr[i]=new Node("sameer",temp);
    // }

    // Build_heap(arr,n);
    // arr[0]=new Node("sameer",4000);
    // min_heapify(arr,0,n);
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<arr[i]->data<<" "<<arr[i]->frequency<<endl;
    // }
    // cout<<endl;

    // }

    return 0;
}