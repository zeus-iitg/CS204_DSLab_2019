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
#define ii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<ii>
#define vpll vector<pll>
#define all(a) a.begin(),a.end()
#define INF INT_MAX

#define o_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define o_setll tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

using namespace std;
using namespace __gnu_pbds;

struct Node{
    ll x;
    ll y;
    struct Node* next;
};

struct Node* head;

struct Node* createNode(ll x,ll y){
    struct Node* temp = new Node;
    temp->x=x;
    temp->y=y;
    return temp;
}

void AddFirst(ll x,ll y){
    struct Node* ptr=createNode(x,y);
    ptr->next=head;
    head=ptr;
}

void DelFirst(){
    if(head==NULL){
        cout<<"-1\n";
        return;
    }
    struct Node* ptr=head;
    head=head->next;
    free(ptr);
}

void Search(long double d){
    struct Node* temp=head;
    ll num=0;
    while(temp){
        long double x_c=temp->x,y_c=temp->y;
        if(d*d>=x_c*x_c+y_c*y_c)
            num++;
        temp=temp->next;
    }
    if(num==0)
        cout<<"-1\n";
    else
        cout<<num<<"\n";
}

bool Search(ll x,ll y){
    struct Node* temp=head;
    while(temp){
    if(x==temp->x&&y==temp->y)
        return true;
        temp=temp->next;
    }
    return false;
}

ll Length(){
    ll ctr=0;
    struct Node* temp=head;
    while(temp){
        ctr++;
        temp=temp->next;
    }
    return ctr;
}

void Del(ll x,ll y){
    if(Search(x,y)){
        struct Node *temp=head,*prev=NULL;
        while(temp){
            if(temp->x==x&&temp->y==y){
                if(prev)
                prev->next=temp->next;
                else
                head=head->next;
                break;
            }
            else{
                prev=temp;
                temp=temp->next;
            }
        }
        free(temp);
    }
    else cout<<"-1\n";
}

int main()
{
    IOS
	head=NULL;
	ll t;
	cin>>t;
	while(t--){
		int f;
		cin>>f;
		if(f==1){
			ll x,y;
			cin>>x>>y;
			AddFirst(x,y);
		}
		else if(f==2){
			DelFirst();
		}
		else if(f==3){
			ll x,y;
			cin>>x>>y;
			Del(x,y);
		}
		else if(f==4){
			long double d;
			cin>>d;
			Search(d);
		}
		else if(f==5)
		{
			ll x,y;
			cin>>x>>y;
			if(Search(x,y))
				cout<<"True\n";
			else cout<<"False\n";
		}
		else{
            ll len=Length();
			cout<<len<<"\n";
		}
	}
	return 0;
}
