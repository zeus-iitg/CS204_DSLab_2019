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
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define F first
#define S second

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

bool dfs(ll x,ll color[],vpll ad[])
{
    bool ans=1;
    for(auto y:ad[x])
    {
        if((color[y.F]+y.S)%2==color[x]) ans=0;
        else if(color[y.F]==-1)
        {
            color[y.F]=(color[x]+y.S)%2;
            ans&=dfs(y.F,color,ad);
        }
    }
    return ans;
}

int main()
{
    IOS
    string n;
    ll m;
    cin>>n>>m;
    string u[m],v[m],w[m];
    map<string,ll> node;
    ll node_size=0;
    REP(i,0,m)
    {
        cin>>u[i]>>v[i]>>w[i];
        if(node.count(u[i])==0)
        {
            node.insert(mp(u[i],node_size));
            node_size++;
        }
        if(node.count(v[i])==0)
        {
            node.insert(mp(v[i],node_size));
            node_size++;
        }
    }
    vpll ad[node_size];
    REP(i,0,m)
    {
        ad[node[u[i]]].pb(mp(node[v[i]],(w[i][w[i].size()-1]-(ll)'0'+10)%2));
        ad[node[v[i]]].pb(mp(node[u[i]],(w[i][w[i].size()-1]-(ll)'0'+10)%2));
    }
    ll color[node_size];
    REP(i,0,node_size)
    {
        color[i]=-1;
    }
    bool ans=1;
    REP(i,0,node_size)
    {
        if(color[i]==-1)
        {
            color[i]=0;
            ans&=dfs(i,color,ad);
        }
    }
    if(ans==1) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}
