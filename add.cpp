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
	getline(cin,str);
	vi num1,num2;
	for(int i=0;i<str.length();i++){
	num1.pb(str[i]-'0');
	}
	getline(cin,str);
	for(int i=0;i<str.length();i++)
	num2.pb(str[i]-'0');
	/*for(int i=0;i<num1.size();i++){
	    cout<<num1[i];
	}
	cout<<"\n";
	for(int i=0;i<num2.size();i++){
	    cout<<num2[i];
	}
	cout<<"\n";*/
	reverse(all(num1));
	reverse(all(num2));
	/*for(int i=0;i<num1.size();i++){
	    cout<<num1[i];
	}
	cout<<"\n";
	for(int i=0;i<num2.size();i++){
	    cout<<num2[i];
	}
	cout<<"\n";*/
	int carry=0;
	vi res;
	//cout<<num1.size()<<" "<<num2.size()<<"\n";
	for(int i=0;i<max(num1.size(),num2.size());i++)
	{
	    //cout<<"i = "<<i<<"\n";
		if(i>=num1.size()){
	    	res.pb(num2[i]+carry);
		carry=res[i]/10;
		res[i]%=10;
		//cout<<carry<<" "<<res[i]<<"\n";
	    }
	    else if(i>=num2.size()){
		res.pb(num1[i]+carry);
		carry=res[i]/10;
		res[i]%=10;
		//cout<<carry<<" "<<res[i]<<"\n";
	    }
	    else{
		res.pb(num2[i]+num1[i]+carry);
		carry=res[i]/10;
		res[i]%=10;
		//cout<<carry<<" "<<res[i]<<"\n";
	    }
	}
	if(carry)
	    res.pb(carry);
	for(int i=res.size()-1;i>=0;i--)
	    cout<<res[i];
	cout<<"\n";
	}
	    return 0;
    }
















