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
#define M 1000000007
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define ff first
#define ss second

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
    int val;
    struct node* left;
    struct node* right;
};
struct node * newnode(int element)
    {
        struct node * temp=(node * )malloc(sizeof(node));
        temp->val=element;
        temp->left=temp->right=NULL;
        return temp;
    }
void create(string s, int val, struct node* src){
    struct node *nd = newnode(val);
    int i=0;
    struct node *top = src;
    while(i< s.size()-1){
        if(s[i] == 'L'){
            top = top->left;
        }
        else if(s[i] == 'R'){
            top=top->right;
        }
        i++;
    }
    if(s[i] == 'L'){
        top->left = nd;
        }
    else if(s[i] == 'R'){
        top->right = nd;
        }
}

int height(struct node *src){
    if(src == NULL){
        return 0;
    }else{
        int ldepth = height(src->left);
        int rdepth = height(src->right);

        if(ldepth > rdepth){
            return (ldepth+1);
        }else{
            return (rdepth+1);
        }
    }
}

int diameter(struct node *src){
    if(src == NULL){
        return 0;
    }
    int rheight = height(src->right);
    int lheight = height(src->left);

    int rdia = diameter(src->left);
    int ldia = diameter(src->right);

    return max(1+lheight+rheight, max(rdia, ldia));
}

int main()
{
    IOS
    int t, x;
    cin>>t>>x;
    struct node *cc, *top;
    top = newnode(x);
    vector<pair<string, int > > vv(0);
    REP(i, 0, t-1){
    string st;
    int a;
    cin>>st>>a;
    vv.pb(make_pair(st, a));
    }
    sort(vv.begin(), vv.end());
    REP(i, 0, t-1){
        cc = top;
        create(vv[i].first, vv[i].second, cc);
    }
    cout<<diameter(top);
}
