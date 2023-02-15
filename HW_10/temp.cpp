//your code goes here
#include<iostream>
#define ll long long int
using namespace std;
// class Node{
//         public: 
//         int neigh1,neigh2,dis;
//         // Node* next;
//         Node(){}
//         Node(int val1,ll val2,ll val3){
//             neigh1 = val1;
//             neigh2 = val2;
//             dis = val3; 
//         }
// };
// class Adjacency_List{
//     ll cap = 200000;
//     ll size = 0;
//     public:
//         Node* arr;
//         Adjacency_List(){
//             arr = new Node[cap];
//         }
//         void insert_neighbour(ll a,ll b,ll dis){
//             // if(size == cap){
//             //     cap = 2*cap;
//             // }
//             arr[size] = Node(a,b,dis);
//             size++;
//         }
//         ll ret_neighbour(ll j){
//             return arr[j].neigh2;
//         }
//         ll ret_neighbour_cost(ll j){
//             return arr[j].dis;
//         }
//         void all_neighbour(){
//             for (ll i = 0; i < size; i++)
//             {
//                 cout<<arr[i].neigh2 +1<<"("<<arr[i].dis<<")"<<" ";
//             } 
//         }
//         ll Size(){
//             return size;
//         }
// };
// class min_Queue{
//     ll* arr;
//     ll size;
//     public:
//         min_Queue(ll n){
//             size = n;
//             arr = new ll[n];
//             arr[0] = 0;
//             for (ll i = 1; i < n; i++)
//             {
//                 arr[i] = 1000000;
//             }
//         }
//         ll extract_min(bool visited[]){
//             ll x = 0;
//             ll min = 10000000;
//             for (ll i = 0; i < size; i++)
//             {
//                 if(!visited[i] && arr[i] < min){
//                     x = i;
//                     min = arr[i];
//                 }
//             }
//             return x;
//         }
//         void update(ll i,ll cst){
//             arr[i] = cst;
//         }
//         ll Cost(ll i){
//             return arr[i];
//         }
// };
// void Dijkstra(Adjacency_List arr[],min_Queue q,ll n){
//     bool visited[n];
//     for (ll i = 0; i < n; i++)
//     {
//         visited[i] = false;
//     }
//     // visited[1] = true;
//     for(ll i = 0;i<n;i++){
//         ll u = q.extract_min(visited);
//         visited[u] = true;
//         // cout<<u<<" "<<arr[u].Size()<<endl;
//         for (ll j = 0; j < arr[u].Size(); j++)
//         {
//             // cout<<q.Cost(arr[u].ret_neighbour(j))<<" "<<q.Cost(u)<<" "<<arr[u].ret_neighbour_cost(j)<<" "<<endl;
//             if(q.Cost(arr[u].ret_neighbour(j)) > q.Cost(u) + (arr[u].ret_neighbour_cost(j))){
//                 ll cst = q.Cost(u) + (arr[u].ret_neighbour_cost(j));
//                 q.update(arr[u].ret_neighbour(j),cst); 
//                 // cout<<cst<<endl;
//                 // visited[j] = true;
//             }
//         }
//         // cout<<q.Cost(u)<<" ";
//     }
// }
int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ll n,m;
    cin>>n>>m;
    ll a,b;
    cin>>a>>b;
    if(m==0){
        cout<<1;
        return 0;
    }
    ll maxi = max(a,b);
    for (ll i = 0; i < m-1; i++)
    {
        cin>>a>>b;
        maxi = max(max(a,b),maxi);
    }
    cout<<n-maxi;
    // Adjacency_List arr[n];
    // for (ll i = 0; i < m; i++)
    // {
    //     ll a,b,c;
    //     cin>>a>>b;
    //     a--;
    //     b--;
    //     c = (a-b)*(a-b);
    //     arr[a].insert_neighbour(a,b,c);
    //     arr[b].insert_neighbour(b,a,c);
    // }
    // for (ll i = 0; i < n; i++)
    // {   
    //     cout<<i+1<<"-->";
    //     arr[i].all_neighbour();
    //     cout<<endl;
    // }
    // min_Queue q(n);
    // Dijkstra(arr,q,n);
    // cout<<"Hello"<<endl;
    // cout<<q.Cost(n-1);
    return 0;
}