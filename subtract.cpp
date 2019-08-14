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
     
    int main()
    {
        IOS
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
        string str;
        bool swapped=false;
	getline(cin,str);
	vi num1,num2;
	for(int i=0;i<str.length();i++){
	num1.pb(str[i]-'0');
	}
	getline(cin,str);
	for(int i=0;i<str.length();i++)
	num2.pb(str[i]-'0');



	if(num1==num2)
	{
	    cout<<"0";
	    return 0;
	}

	int carry=0;
	vi res;

	if(num2.size()>num1.size()){
	    vi temp=num1;
	    num1=num2;
	    num2=temp;
	    swapped=true;
	}

	bool swap=false;
	if(num1.size()==num2.size()){
	    for(int i=0;i<num1.size();i++){
		if(num1[i]>num2[i])
		break;
		else if(num1[i]<num2[i]){
		    swap=true;
		    break;
		}
	    }
	    if(swap){
		vi temp=num1;
		num1=num2;
		num2=temp;
		swapped=true;
	    }
	}


	reverse(all(num1));
	reverse(all(num2));


	for(int i=0;i<num2.size();i++)
	{
	    
		if(num1[i]>=num2[i])
		res.pb(num1[i]-num2[i]);
		else{
		    int start=i+1;
		    int itr=i+1;
		    while(num1[itr]==0)
		    itr++;
		    num1[itr]--;
		    for(int var=start;var<itr;var++)
		    num1[var]=9;
		    res.pb(10+num1[i]-num2[i]);
		}
	}

	for(int i=num2.size();i<num1.size();i++)
	res.pb(num1[i]);

	if(swapped)
	cout<<"-";
	int i;
	i=res.size()-1;
	while(res[i]==0)
	i--;

	for(;i>=0;i--)
	    cout<<res[i];
	cout<<"\n";
	}
    return 0;
    }
















