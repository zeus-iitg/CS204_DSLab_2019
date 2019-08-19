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

ll pow(ll base,ll power){
	ll res=1;
	for(int i=0;i<power;i++)
		res*=base;
	return res;
}

// An expression tree node 
struct et 
{ 
    string value; 
    et* left, *right; 
}; 
  
// A utility function to check if 'c' 
// is an operator 
bool isOperator(string c) 
{ 
    if (c == "+" || c == "-" || 
            c == "*" || c == "/" || 
            c == "^") 
        return true; 
    return false; 
} 
  
// Utility function to do inorder traversal 
void postorder(et *t) 
{ 
    if(t) 
    { 
        postorder(t->left);  
        postorder(t->right);
        cout<<t->value<<" "; 
    } 
} 
  
// A utility function to create a new node 
et* newNode(string v) 
{ 
    et *temp = new et; 
    temp->left = temp->right = NULL; 
    temp->value = v; 
    return temp; 
}; 
  
// Returns root of constructed tree for given 
// postfix expression 
et* constructTree(vector<string> postfix) 
{ 
    stack<et *> st; 
    et *t, *t1, *t2; 
  
    // Traverse through every character of 
    // input expression 
    for (int i=0; i<postfix.size() ; i++) 
    { 
        // If operand, simply push into stack 
        if (!isOperator(postfix[i])) 
        { 
            t = newNode(postfix[i]); 
            st.push(t); 
        } 
        else // operator 
        { 
            t = newNode(postfix[i]); 
  
            // Pop two top nodes 
            t1 = st.top(); // Store top 
            st.pop();      // Remove top 
            t2 = st.top(); 
            st.pop(); 
  
            //  make them children 
            t->right = t1; 
            t->left = t2; 
  
            // Add this subexpression to stack 
            st.push(t); 
        } 
    } 
  
    //  only element will be root of expression 
    // tree 
    t = st.top(); 
    st.pop(); 
  
    return t; 
} 

//Function to return precedence of operators 
int prec(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 

ll eval(et* root)  
{  
    // empty tree  
    if (!root)  
        return 0;  
  
    // leaf node i.e, an integer  
    if (!root->left && !root->right)  
        return stoll(root->value);  
  
    // Evaluate left subtree  
    ll l_val = eval(root->left);  
  
    // Evaluate right subtree  
    ll r_val = eval(root->right);  
  
    // Check which operator to apply  
    if (root->value=="+")  
        return l_val+r_val;  
  
    if (root->value=="-")  
        return l_val-r_val;  
  
    if (root->value=="*")  
        return l_val*r_val;  
        
    if (root->value=="/")
    	return l_val/r_val;
    	
    return pow(l_val,r_val);  
}
  
// The main function to convert infix expression 
//to postfix expression 
void infixToPostfix(string s) 
{ 
    std::stack<char> st; 
    st.push('N'); 
    int l = s.length(); 
    vector<string> ns;
    ll num=0; 
    for(int i = 0; i < l; i++) 
    { 
        // If the scanned character is an operand, add it to output string. 
        if(s[i] >= '0' && s[i] <= '9') 
        {
        	int j=i;
        	while((s[j] >= '0' && s[j] <= '9')&&( j<s.length() )){
        		num=num*10+s[j]-'0';
        		j++;
        	}
        	i=j-1;
        	ns.pb(to_string(num));
        	num=0;
        	continue;
        } 
  
        // If the scanned character is an ‘(‘, push it to the stack. 
        else if(s[i] == '(') 
          
        st.push('('); 
          
        // If the scanned character is an ‘)’, pop and to output string from the stack 
        // until an ‘(‘ is encountered. 
        else if(s[i] == ')') 
        { 
            while(st.top() != 'N' && st.top() != '(') 
            { 
                char c = st.top(); 
                st.pop(); 
                string str="";
                str+=c;
               ns.pb(str); 
            } 
            if(st.top() == '(') 
            { 
                char c = st.top(); 
                st.pop(); 
            } 
        } 
          
        //If an operator is scanned 
        else{ 
            while(st.top() != 'N' && prec(s[i]) <= prec(st.top())) 
            { 
                char c = st.top(); 
                st.pop(); 
                string str="";
                str+=c;
                ns.pb(str); 
            } 
            st.push(s[i]); 
        } 
  
    } 
    //Pop all the remaining elements from the stack 
    while(st.top() != 'N') 
    { 
        char c = st.top(); 
        st.pop(); 
        string str="";
        str+=c;
        ns.pb(str);
    } 
    
    et* r = constructTree(ns);
    
    stack<ll> numbers;
    for(int i=0;i<ns.size();i++){
    	if(ns[i]=="+"||ns[i]=="-"||ns[i]=="*"||ns[i]=="/"||ns[i]=="^")
    	{
    		ll num1=numbers.top();
    		numbers.pop();
    		ll num2=numbers.top();
    		numbers.pop();
    		ll res;
    		if(ns[i]=="+"){
    			res=num2+num1;
    		}
    		else if(ns[i]=="-"){
    			res=num2-num1;
    		}
    		else if(ns[i]=="*"){
    			res=num2*num1;
    		}
    		else if(ns[i]=="/"){
    			res=num2/num1;
    		}
    		else if(ns[i]=="^"){
    			res=pow(num2,num1);
    		}
    		numbers.push(res);
    	}
    	else{
    		numbers.push(stoll(ns[i]));
    	}
    }
    ll print=numbers.top();
    //cout<<print;
    
    ll result=eval(r);
    cout<<result;
}



int main()
{
	ll n;
	cin>>n;
	cin.ignore();
	while(n--){
		ll rows;
		cin>>rows;
		cin.ignore();
		while(rows--){
			string str;
			getline(cin,str);
			infixToPostfix(str);
			cout<<"\n";
		}
	}
    return 0;
}







