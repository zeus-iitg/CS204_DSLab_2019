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
#define ii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<ii>
#define vpll vector<pll>
#define all(a) a.begin(),a.end()
#define INF LLONG_MAX

#define o_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define o_setll tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

using namespace std;
using namespace __gnu_pbds;

class BSTNode
{
public:
    string variable;
    long long value;
    BSTNode* Left;
    BSTNode* Right;
}*root=nullptr;

BSTNode* create_node(string str,ll val){
    BSTNode* temp=new BSTNode;
    temp->variable=str;
    temp->value=val;
    temp->Left=nullptr;
    temp->Right=nullptr;
    return temp;
}

int lesser(string str1,string str2){
    int i=0;
    while(i<min(str1.length(),str2.length())){
        if(str1[i]<str2[i])
            return 1;
        else if(str1[i]>str2[i])
            return 2;
        i++;
    }
    if(str1.length()<str2.length())
        return 1;
    else if(str1.length()>str2.length())
        return 2;
    else return 0;
}

void insert_node(string str,long long value){
    if(root==nullptr){
        root=create_node(str,value);
        return;
    }
    BSTNode *temp=root,*last=nullptr;
    int a;
    while(temp){
        last=temp;
        a=lesser(temp->variable,str);
        if(a==1){
            temp=temp->Right;
        }
        else if(a==2){
            temp=temp->Left;
        }
        else break;
    }
    if(temp==nullptr){
        if(a==1)
            last->Right=create_node(str,value);
        else
            last->Left=create_node(str,value);
    }
    else temp->value=value;
    return;
}

BSTNode* search_node(string str){
    BSTNode *temp=root;
    int a;
    while(temp){
        a=lesser(temp->variable,str);
        if(a==1){
            temp=temp->Right;
        }
        else if(a==2){
            temp=temp->Left;
        }
        else break;
    }
    return temp;
}

ll pow(ll base,ll power){
    if(power<0)
        return 0;
	ll res=1;
	for(int i=0;i<power;i++)
		res*=base;
	return res;
}

struct et
{
    string value;
    et* left, *right;
};

bool isOperator(string c)
{
    if (c == "+" || c == "-" ||
            c == "*" || c == "/" ||
            c == "^")
        return true;
    return false;
}

bool isOperator(char c)
{
    if (c == '+' || c == '-' ||
            c == '*' || c == '/' ||
            c == '^')
        return true;
    return false;
}

void postorder(et *t)
{
    if(t)
    {
        postorder(t->left);
        postorder(t->right);
        cout<<t->value<<" ";
    }
}

et* newNode(string v)
{
    et *temp = new et;
    temp->left = temp->right = NULL;
    temp->value = v;
    return temp;
};

et* constructTree(vector<string> postfix)
{
    stack<et *> st;
    et *t, *t1, *t2;

    for (int i=0; i<postfix.size() ; i++)
    {
        if (!isOperator(postfix[i]))
        {
            t = newNode(postfix[i]);
            st.push(t);
        }
        else
        {
            t = newNode(postfix[i]);

            t1 = st.top();
            st.pop();
            t2 = st.top();
            st.pop();

            t->right = t1;
            t->left = t2;

            st.push(t);
        }
    }

    t = st.top();
    st.pop();

    return t;
}

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
    if (!root)
        return 0;

    if (!root->left && !root->right){
        bool is_number=true;
        for(int i=0;i<root->value.size();i++)
        {
            if(root->value[i]>='0'&&root->value[i]<='9')
                continue;
            else{
                is_number=false;
                break;
            }
        }
        if(is_number)
            return stoll(root->value);
        else
        {
            BSTNode* node=search_node(root->value);
            return node->value;
        }
    }

    ll l_val = eval(root->left);

    ll r_val = eval(root->right);

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

int cnt=0;

bool cant_be_evaluated=false;

ll evaluate_value(string s){
    std::stack<char> st;
    st.push('N');
    int l = s.length();
    vector<string> ns;
    for(int i = 0; i < l; i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
        	int j=i;
        	string str;
        	while(( j<s.length() )&&(s[j] >= '0' && s[j] <= '9')){
        		str.pb(s[j]);
        		j++;
        	}
        	i=j-1;
        	ns.pb(str);
        	if(cnt)
                goto label;
        	continue;
        }

        else if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
            int j=i;
            string var;
        	while((s[j]>='a'&&s[j]<='z')||(s[j]>='A'&&s[j]<='Z')){
        		var.pb(s[j]);
        		j++;
        	}
        	i=j-1;
        	ns.pb(var);
        	if(cnt)
                goto label;
        	continue;
        }
        else if(s[i] == ')')
        {
            label:
            while(st.top() != 'N' && st.top() != '(')
            {
                char c = st.top();
                st.pop();
                string str="";
                str+=c;
               ns.pb(str);
            }
            if(st.top() == '(')
                st.pop();
            if(cnt)
                cnt--;
            if(cnt)
                goto label;
            else continue;
        }

        else if(s[i] == '(')

        st.push('(');

        else{
            if(s[i]=='-'&&(i==0||s[i-1]=='('||isOperator(s[i-1]))){
                cnt++;
                st.push('(');
                ns.pb("0");
               }
            while(st.top() != 'N' && prec(s[i]) <= prec(st.top()))
            {
            	if(s[i]=='^'&&st.top()=='^')
            		break;
                char c = st.top();
                st.pop();
                string str="";
                str+=c;
                ns.pb(str);
            }
            st.push(s[i]);
        }

    }
    while(st.top() != 'N')
    {
        char c = st.top();
        st.pop();
        string str="";
        str+=c;
        ns.pb(str);
    }

    for(int i=0;i<ns.size();i++){
        if(isOperator(ns[i]))
            continue;
        bool is_number=true;
        for(int j=0;j<ns[i].size();j++)
        {
            if(ns[i][j]>='0'&&ns[i][j]<='9')
                continue;
            else{
                is_number=false;
                break;
            }
        }
        if(!is_number){
            BSTNode* node=search_node(ns[i]);
            if(node==nullptr)
            {
                cant_be_evaluated=true;
                return 0;
            }
        }
    }

    et* r = constructTree(ns);

    ll result=eval(r);
    return result;
}

void infixToPostfix(string s)
{


    bool is_assignment=false;
    int i;
    for(i=0;i<s.length();i++)
    {
        if(s[i]=='='){
            is_assignment=true;
            break;
        }
    }
    if(is_assignment){
        ll value=evaluate_value(s.substr(i+1,s.length()-i-2));
        string variable=s.substr(1,i-1);
        if(cant_be_evaluated){
            cout<<"CANT BE EVALUATED\n";
            cant_be_evaluated=false;
        }
        else
            insert_node(variable,value);
        return;
    }


    std::stack<char> st;
    st.push('N');
    int l = s.length();
    vector<string> ns;
    for(int i = 0; i < l; i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
        	int j=i;
        	string str;
        	while(( j<s.length() )&&(s[j] >= '0' && s[j] <= '9')){
        		str.pb(s[j]);
        		j++;
        	}
        	i=j-1;
        	ns.pb(str);
        	if(cnt)
                goto label;
        	continue;
        }

        else if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
            int j=i;
            string var;
        	while((s[j]>='a'&&s[j]<='z')||(s[j]>='A'&&s[j]<='Z')){
        		var.pb(s[j]);
        		j++;
        	}
        	i=j-1;
        	ns.pb(var);
        	if(cnt)
                goto label;
        	continue;
        }
        else if(s[i] == ')')
        {
            label:
            while(st.top() != 'N' && st.top() != '(')
            {
                char c = st.top();
                st.pop();
                string str="";
                str+=c;
               ns.pb(str);
            }
            if(st.top() == '(')
                st.pop();
            if(cnt)
                cnt--;
            if(cnt)
                goto label;
            else continue;
        }

        else if(s[i] == '(')

        st.push('(');

        else{
            if(s[i]=='-'&&(i==0||s[i-1]=='('||isOperator(s[i-1]))){
                cnt++;
                st.push('(');
                ns.pb("0");
               }
            while(st.top() != 'N' && prec(s[i]) <= prec(st.top()))
            {
            	if(s[i]=='^'&&st.top()=='^')
            		break;
                char c = st.top();
                st.pop();
                string str="";
                str+=c;
                ns.pb(str);
            }
            st.push(s[i]);
        }

    }
    while(st.top() != 'N')
    {
        char c = st.top();
        st.pop();
        string str="";
        str+=c;
        ns.pb(str);
    }

    for(int i=0;i<ns.size();i++){
        if(isOperator(ns[i]))
            continue;
        bool is_number=true;
        for(int j=0;j<ns[i].size();j++)
        {
            if(ns[i][j]>='0'&&ns[i][j]<='9')
                continue;
            else{
                is_number=false;
                break;
            }
        }
        if(!is_number){
            BSTNode* node=search_node(ns[i]);
            if(node==nullptr)
            {
                cout<<"CANT BE EVALUATED\n";
                return;
            }
        }
    }

    et* r = constructTree(ns);

    ll result=eval(r);
    cout<<result<<"\n";
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
			string str="(",str2;
			getline(cin,str2);
			str+=str2;
			str+=")";
			infixToPostfix(str);
		}
		free(root);
        root=nullptr;
	}
    return 0;
}
