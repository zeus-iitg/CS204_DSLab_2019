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

struct cnode
{
    int value;
    int p;
    cnode* leftp;
    cnode* rightp;
};
cnode* leftprotate(cnode* y)
{
    cnode* x= y->rightp;
    cnode* t2= x->leftp;
    x->leftp= y;
    y->rightp= t2;
    return x;
}

cnode* rightprotate(cnode* x)
{
    cnode* y= x->leftp;
    cnode* t2= y->rightp;
    y->rightp= x;
    x->leftp= t2;
    return y;
}

cnode* newnode(int x)
{
    cnode* temp= new cnode;
    temp->value= x;
    temp->p= rand()%100;
    temp->leftp=NULL;
    temp->rightp= NULL;
    return temp;
}

cnode* search(cnode* root, int value)
{
    if(root==NULL || root->value==value)
    {
        return root;
    }

    if(root->value>value)
    {
        return search(root->leftp, value);
    }
    if(root->value<value)
    {
        return search(root->rightp, value);
    }
}

cnode* insert(cnode* root, int value)
{
    if(root==NULL)
    {
        return newnode(value);
    }

    if(root->value>=value)
    {
        root->leftp= insert(root->leftp, value);
        if(root->leftp->p>root->p)
        {
            root= rightprotate(root);
        }
    }
    else if(root->value<value)
    {
        root->rightp= insert(root->rightp, value);
        if(root->rightp->p>root->p)
        {
            root= leftprotate(root);
        }
    }

    return root;
}

cnode* deletenode(cnode* root, int value)
{
    if(root==NULL)
    {
        return root;
    }
    //If value is not equal to root's value, we check in its rightp or leftp subtree//
    if(root->value>value)
    {
        root->leftp= deletenode(root->leftp, value);
    }
    else if(root->value<value)
    {
        root->rightp= deletenode(root->rightp, value);
    }
    else if(root->value==value)
    {
        if(root->leftp==NULL)
        {
            cnode* temp= root->rightp;
            delete(root);
            root= temp;
        }
        else if(root->rightp==NULL)
        {
            cnode* temp= root->leftp;
            delete(root);
            root= temp;
        }
        else if(root->leftp!=NULL && root->rightp!=NULL)
        {
            if(root->leftp->p>root->rightp->p)
            {
                root= rightprotate(root);
                root->rightp= deletenode(root->rightp, value);
            }
            else if(root->rightp->p>root->leftp->p)
            {
                root= leftprotate(root);
                root->leftp= deletenode(root->leftp, value);
            }
        }
    }
    return root;
}

void inorder(cnode* root)
{
    if (root!=NULL)
    {
        inorder(root->leftp);
        cout << "value: "<< root->value << " | Priority: "
            << root->p;
        if (root->leftp)
            cout << " | leftp child: " << root->leftp->value;
        if (root->rightp)
            cout << " | rightp child: " << root->rightp->value;
        cout << endl;
        inorder(root->rightp);
    }
}
int main()
{
    IOS
    struct cnode *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 120);
    root = insert(root, 102);

    cout << "Inorder traversal of the given tree \n";
    inorder(root);

    root = deletenode(root, 20);
    cout << "Inorder traversal of the modified tree after deletion of 20 \n";
    inorder(root);

    root = deletenode(root, 30);
    cout << "Inorder traversal of the modified tree after deletion of 30 \n";
    inorder(root);

    root = deletenode(root, 50);
    cout << "Inorder traversal of the modified tree after deletion of 50\n";
    inorder(root);

    cnode *res = search(root, 50);
    if(res==NULL)
    {
        cout<<"50 is not Found!!!" <<endl;
    }
    else
    {
        cout<< "50 is found!!!" <<endl;
    }
    return 0;
}
