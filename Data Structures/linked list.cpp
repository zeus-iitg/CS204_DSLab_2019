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

struct node
{
    int x;
    int y;
    struct node *next;
};

struct node *head = NULL;

void addfirst(int a,int b)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->x = a;
    temp->y = b;
    temp->next = head;
    head = temp;
}

int delfirst()
{
    struct node *temp;
    if(head == NULL)
    {
        return -1;
    };
    temp = head;
    head = head->next;
    delete temp;
    temp = NULL;
    return 1;
}

int del(int a,int b)
{
    struct node *temp,*prev = NULL;
    temp = head;
    int f=0;
    while(temp != NULL)
    {
        if(temp->x==a  && temp->y==b)
        {
            struct node *temp2;
            temp2= temp->next;
            if(prev==NULL){
                head= temp2;

                delete(temp);
                temp = NULL;
            }
            else{
                prev->next = temp2;
                delete(temp);
                temp = NULL;
            }
            return 1;
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }
    return -1;
}

void search(long long int d)
{
    struct node *temp;
    int flag=0;
    temp = head;
    long long int f;
    long long int a,b;
    while(temp!= NULL){
        a = temp->x;
        b= temp->y;
        f = (a*a + b*b);
        //cout<<a;
        //f = f*f;
        //cout<<f;
        if(f<=d*d)
        {
            cout<<"("<<temp->x<<","<<temp->y<<") ";
            flag++;
        };
        temp = temp->next;
    };
    if(flag==0)
    {
        cout<<"-1" <<endl;
    }
    else{
        cout<<"\n";
    }
}

bool searchpoint(int a,int b)
{
    struct node *temp;
    temp = head;
    while(temp!=  NULL)
    {
        if(temp->x == a  && temp->y==b){
            return true;
        }
        temp= temp->next;
    };
    return false;
};

int length(){
    int counter=0;
    struct node *temp;
    temp = head;
    while(temp!= NULL)
    {
        counter++;
        temp = temp->next;
    }
    return counter;
}

int main()
{
    IOS
    int a,b,c;
    int t;
    long long int d;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>a;
        if(a==1)
        {
            cin>>b>>c;
            addfirst(b,c);
        }
        else if(a==2)
        {
            cout<< delfirst() <<endl;
        }
        else if(a==3)
        {
            cin>>b>>c;
            cout<< del(b,c) <<endl;
        }
        else if(a==4){
            cin>>d;
            search (d);
        }
        else if(a==5){
            cin>>b>>c;

            if(searchpoint(b,c))cout<<"TRUE" <<endl;
            else cout<<"FALSE" <<endl;
        }
        else
            {

            b= length();
            cout<<b<<endl;
        };
    };
    return 0;
}
