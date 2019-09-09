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
     
#define o_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define o_setll tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set
     
using namespace std;
using namespace __gnu_pbds;

bool compare(string s1, string s2)
{  
    string str1 = s1.append(s2); 
  
    string str2 = s2.append(s1); 
  
    return str1.compare(str2) > 0 ; 
} 

void printLargest(vector<string> arr) 
{ 
    sort(arr.begin(), arr.end(), compare); 
  
    for (ll i=0; i < arr.size() ; i++ ) 
        cout << arr[i]; 
} 
 
int main()
{
    IOS
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		cin.ignore();
		vector<string> vec(n);
		for(ll i=0;i<n;i++)
			getline(cin,vec[i]);
		printLargest(vec);
		cout<<"\n";
	}
    return 0;
}

