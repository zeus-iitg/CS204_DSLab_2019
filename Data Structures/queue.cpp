#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include <time.h>
#include <stdlib.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define ull unsigned long long
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/__gcd((a),(b))
#define clr(x) x.clear()
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vi>
#define mp make_pair
#define hell 1000000007
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define all(a) a.begin(),a.end()
#define ign cin.ignore();
#define lli long long
 
#define o_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define o_setll tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set
 
using namespace std;
using namespace __gnu_pbds;
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

struct node{
    lli data;
    node *next;
};
class Queue{
    public:
    void enqueue(lli x)
    {
        node *t=(node *)malloc(sizeof(node));
        t->data=x;
        t->next=NULL;
        if(this->start==NULL)
        {
            this->end=t;
            this->start=t;
        }
        else{
        this->end->next=t;
        this->end=t;
        }
        cout<<"Added "<<x<<endl;
    }
    lli dequeue(void)
    {
        node *t=this->start;
        if(!t)
        {
            cout<<"Queue is empty!!"<<endl;
            return 0;
        }
        this->start=t->next;
        lli x=t->data;
        delete t;
        cout<<x<<" Deleted"<<endl;
        return x;
    }
    void show()
    {
        node *t=this->start;
        while(t!=NULL)
        {
            cout<<t->data<<' ';
            t=t->next;
        }    
        cout<<endl;
    }
    Queue()
    {
        this->end=NULL;
        this->start=NULL;
    }
    private:
    node *start,*end;
};

int main()
{
    IOS
    Queue Q;
    while(1){
        cout<<"Enter choice : \n 1. Enqueue \n 2. Dequeue \n 3. Show \n 4. Exit \n";
        lli x;
        lli c;
        cin>>c;
        switch(c)
        {
            case 1: cin>>x;
                    Q.enqueue(x);
                    break;
            case 2: Q.dequeue();
                    break;
            case 3: Q.show();
                    break;
            case 4: return 0;
            default: cout<<"Wrong choice!!"<<endl;
        }
    }
    return 0;
}
