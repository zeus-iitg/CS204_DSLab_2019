//LINK TO PROBLEM: https://cses.fi/problemset/task/1193
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
 
vector<vector<char>> arr;
int n,m;
 
int sx,sy,ex,ey;
 
int main()
{
    IOS
    cin>>n>>m;
 
    arr.resize(n);
    for(int i=0;i<n;i++)
    {
        arr[i].resize(m);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]=='A')
            {
                sx=i;
                sy=j;
            }
            if(arr[i][j]=='B')
            {
                ex=i;
                ey=j;
            }
        }
        ign
    }
    vector<vector<bool>> used;
    used.resize(n);
    for(int i=0;i<n;i++)
    {
        used[i].resize(m);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            used[i][j]=false;
        }
    }
    queue<pii> q;
 
    vector<vector<int>> d;
    vector<vector<pii>> p;
    d.resize(n);
    for(int i=0;i<n;i++)
    {
        d[i].resize(m);
    }
 
    p.resize(n);
    for(int i=0;i<n;i++)
    {
        p[i].resize(m);
    }
 
    q.push({sx,sy});
    used[sx][sy] = true;
    d[sx][sy]=0;
    p[sx][sy]={-1,-1};
    while (!q.empty()) {
        pii v = q.front();
        q.pop();
        int i=v.first;
        int j=v.second;
        if(i==ex&&j==ey)
        {
            cout<<"YES\n";
            cout<<d[i][j]<<"\n";
            break;
        }
        if(i+1<n){
            if (!used[i+1][j]&&arr[i+1][j]!='#') {
                used[i+1][j] = true;
                q.push({i+1,j});
                d[i+1][j] = d[i][j] + 1;
                p[i+1][j] = {i,j};
            }
        }
        if(i-1>=0){
            if (!used[i-1][j]&&arr[i-1][j]!='#') {
                used[i-1][j] = true;
                q.push({i-1,j});
                d[i-1][j] = d[i][j] + 1;
                p[i-1][j] = {i,j};
            }
        }
        if(j+1<m){
            if (!used[i][j+1]&&arr[i][j+1]!='#') {
                used[i][j+1] = true;
                q.push({i,j+1});
                d[i][j+1] = d[i][j] + 1;
                p[i][j+1] = {i,j};
            }
        }
        if(j-1>=0){
            if (!used[i][j-1]&&arr[i][j-1]!='#') {
                used[i][j-1] = true;
                q.push({i,j-1});
                d[i][j-1] = d[i][j] + 1;
                p[i][j-1] = {i,j};
            }
        }
    }
    if(!used[ex][ey])
        cout<<"NO\n";
    else{
        vector<pii> path;
        for (pii v = (pii){ex,ey}; v != (pii){-1,-1}; v = p[v.first][v.second])
            path.push_back(v);
        reverse(path.begin(), path.end());
        for(int i=1;i<path.size();i++){
            if(path[i].first==path[i-1].first){
                if(path[i].second==path[i-1].second+1)
                    cout<<"R";
                else
                    cout<<"L";
            }
            else{
                if(path[i].first==path[i-1].first+1)
                    cout<<"D";
                else
                    cout<<"U";
            }
        }
        //debug(path);
    }
    return 0;
}
