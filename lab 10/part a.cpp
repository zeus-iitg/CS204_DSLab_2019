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
#define hell 1000000007
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define all(a) a.begin(),a.end()
#define ign cin.ignore();
#define ll long long
#define V(a) vector<a>
#define MP make_pair
#define REP(i,a,b) for(ll i=a;i<b;i++)

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

ll find(ll rank[],ll x)
{
    if(rank[x]==x) return x;
    else return rank[x]=find(rank,rank[x]);
}

void un(ll size[],ll rank[],ll x,ll y)
{
    x=find(rank,x);
    y=find(rank,y);
    if(x==y) return;
    if(size[x]<size[y]) swap(x,y);
    size[x]+=size[y];
    rank[y]=x;
    return;
}

int main()
{
    IOS
    string m,n;
    cin>>m>>n;
    ll k;
    cin>>k;
    map<pll,ll> mp;
    ll rank[k];
    ll size[k];
    ll xcor[k],ycor[k];
    REP(i,0,k)
    {
        ll x,y;
        cin>>x>>y;
        xcor[i]=x;
        ycor[i]=y;
        rank[i]=i;
        size[i]=1;
        mp.insert(MP(MP(x,y),i));
    }
    REP(i,0,k)
    {
        if(mp.count(MP(xcor[i]+1,ycor[i]))!=0) un(size,rank,mp[MP(xcor[i]+1,ycor[i])],i);
        if(mp.count(MP(xcor[i]-1,ycor[i]))!=0) un(size,rank,mp[MP(xcor[i]-1,ycor[i])],i);
        if(mp.count(MP(xcor[i],ycor[i]+1))!=0) un(size,rank,mp[MP(xcor[i],ycor[i]+1)],i);
        if(mp.count(MP(xcor[i],ycor[i]-1))!=0) un(size,rank,mp[MP(xcor[i],ycor[i]-1)],i);
    }
    ll ans=0;
    REP(i,0,k) ans=max(ans,size[i]);
    cout<<ans;

    return 0;
}
