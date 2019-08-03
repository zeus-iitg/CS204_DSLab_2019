/*Author   : Vaibhav Kumar Singh
  Roll No. : 180101086*/
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

#define o_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define o_setll tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

using namespace std;
using namespace __gnu_pbds;

//code starts here

bool first_is_bigger(vi vec1,vi vec2,int i,int j){
    if(vec2.size()>j-i+1)
        return false;
    else if(vec2.size()<j-i+1)
        return true;
    else{
        for(int k=i;k<=j;k++){
            if(vec1[k]>vec2[k-i])
                return true;
            if(vec1[k]<vec2[k-i])
                return false;
        }
        return true;
    }
}

//IMPORTANT NOTE : INPUT TAKES TWO NUMBERS SEPARATED BY A WHITESPACE
//FORMAT OF INPUT
//number1 number2
//OUTPUT GIVES quotient(number1/number2) AND remainder(number1%number2)

int main()
{
    IOS
    //take input as string
    string str;
    getline(cin,str);
    //storing numbers in two vectors
    vi num1,num2;
    int i;
    bool flag=false;
    for(i=0;;i++)
    {
        if(str[i]==' ')
            break;
        else{
            if(str[i]=='0'&&flag==false)
                continue;
            else{
                num1.pb(str[i]-'0');
                flag=true;
            }
        }
    }
    if(num1.size()==0)
        num1.pb(0);
    i++;
    flag=false;
    for(;i<str.length();i++)
    {
        if(str[i]=='0'&&flag==false)
            continue;
        else{
            num2.pb(str[i]-'0');
            flag=true;
        }
    }
    if(num2.size()==0)
        num2.pb(0);
    //checking if second number is zero
    bool iszero=true;
    for(int i=0;i<num2.size();i++)
        if(num2[i]){
            iszero=false;
            break;
        }
    if(iszero){
        cout<<"division by zero is not allowed\n";
        exit(0);
    }
    //if first number is smaller than the second number
    if(!first_is_bigger(num1,num2,0,num1.size()-1))
    {
        cout<<"quotient = 0\n";
        cout<<"remainder = ";
        for(int i=0;i<num1.size();i++)
        {
            cout<<num1[i];
        }
    }
    //if first number is greater than or equal to the second number
    else{
        int len=num2.size();
        int i=0;
        int j=len-1;
        vi quotient;
        int ctr=0;
        for(;;){
            while(i<j&&num1[i]==0)
                i++;
            if(!first_is_bigger(num1,num2,i,j)){
                j++;
                quotient.pb(ctr);
                ctr=0;
                //division over
                if(j==num1.size()){
                    cout<<"quotient = ";
                    int it=0;
                    while(it<quotient.size()-1&&quotient[it]==0)
                        it++;
                    for(;it<quotient.size();it++)
                    {
                        cout<<quotient[it];
                    }
                    cout<<"\n";
                    cout<<"remainder = ";
                    while(i<num1.size()&&num1[i]==0)
                        i++;
                    if(i==num1.size())
                        cout<<"0";
                    else{
                        for(int temp=i;temp<num1.size();temp++)
                            cout<<num1[temp];
                    }
                    exit(0);
                }
            }
            else{
                int start=(j-i+1)==num2.size()?i:i+1;
                for(int itr=start;itr<=j;itr++){
                    if(num1[itr]>=num2[itr-start])
                        num1[itr]-=num2[itr-start];
                    else{
                        int cur=itr;
                        int find;
                        for(find=itr-1;;find--){
                            if(num1[find]!=0)
                                break;
                        }
                        num1[find]--;
                        for(int var=itr-1;var>find;var--){
                            num1[var]=9;
                        }
                        num1[itr]=num1[itr]+10-num2[itr-start];
                    }
                }
                ctr++;
            }
        }
    }
    return 0;
}
