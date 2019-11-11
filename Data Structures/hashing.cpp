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

const int N= 4e6;

struct bucket
{
    list <int> a;
};

struct bucket table[N];
int buckets;

int hashfunction(int x)
{
    return x%buckets;
}

void insert(int x)
{
    int index= hashfunction(x);
    table[index].a.push_back(x);
}

void deleteitem(int x)
{
    int index= hashfunction(x);
    int f=0;
    for(auto i: table[index].a)
    {
        if(i==x)
        {
            f=1;
            break;
        }
    }
    if(f)
    {
        table[index].a.remove(x);
    }
}

void display_hashtable()
{
    for(int i=0; i<buckets; i++)
    {
        cout<<"Bucket " <<i <<" :";
        for(auto ass: table[i].a)
        {
            cout<< ass <<"| ";
        }
        cout<<endl;
    }
}

int main()
{
    IOS
    cin>>buckets;
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>> x;
        insert(x);
    }
    cout<<"After insertion: " <<endl;
    display_hashtable();
    int h;
    cin>> h;
    while(h--)
    {
        int x;
        cin>>x;
        deleteitem(x);
    }
    cout<< "After deletion: " <<endl;
    display_hashtable();
    return 0;
}
