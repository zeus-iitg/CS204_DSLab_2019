LINK TO SUBMISSION: http://codeforces.com/contest/1245/problem/D
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
 
vector<int> parent, rnk;
 
void make_set(int v) {
    parent[v] = v;
    rnk[v] = 0;
}
 
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
 
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b])
            rnk[a]++;
    }
}
 
struct Edge {
    ll u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};
 
int main()
{
    IOS
    ll n;
    cin>>n;
    vpii v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i].first>>v[i].second;
    }
    vll cst(n);
    for(int i=0;i<n;i++)
    {
        cin>>cst[i];
    }
    vll k(n);
    for(int i=0;i<n;i++)
    {
        cin>>k[i];
    }
    vector<Edge> edges;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
        struct Edge e;
        e.u=i+1;
        e.v=j+1;
        e.weight=(k[i]+k[j])*(abs(v[i].first-v[j].first)+abs(v[i].second-v[j].second));
        edges.pb(e);
        }
    }
    for(int i=0;i<n;i++)
    {
        struct Edge e;
        e.u=i+1;
        e.v=0;
        e.weight=cst[i];
        edges.pb(e);
    }
    ll cost = 0;
    n++;
    parent.resize(n);
    rnk.resize(n);
    vector<Edge> result;
    for (int i = 0; i < n; i++)
        make_set(i);
 
    sort(edges.begin(), edges.end());
    vi pwr;
 
    for (Edge e : edges) {
        if (find_set(e.u) != find_set(e.v)) {
            cost += e.weight;
            if(e.v!=0)
                result.push_back(e);
            else
                pwr.pb(e.u);
            union_sets(e.u, e.v);
        }
    }
 
    cout<<cost<<"\n";
    cout<<pwr.size()<<"\n";
    for(int i=0;i<pwr.size();i++)
    {
        cout<<pwr[i]<<" ";
    }
    cout<<"\n";
    cout<<result.size()<<"\n";
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i].u<<" "<<result[i].v<<"\n";
    }
    return 0;
}
