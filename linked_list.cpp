    //#pragma GCC optimize("Ofast")
    //#pragma GCC target("avx,avx2,fma")
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
int x;
int y;
struct Node* next;
};

struct Node* head;

struct Node* createNode(int x,int y){
struct Node* temp = new Node;
temp->x=x;
temp->y=y;
return temp;
}

void AddFirst(int x,int y){
struct Node* ptr=createNode(x,y);
ptr->next=head;
head=ptr;
}

void DelFirst(){
if(head==NULL)
{
cout<<"-1\n";
return;
}
struct Node* ptr=head;
head=head->next;
free(ptr);
cout<<"0\n";
}

void Search(float d){
struct Node* temp=head;
bool found=false;
while(temp){
if(d*d>=temp->x*temp->x+temp->y*temp->y){
found=true;
cout<<"("<<temp->x<<","<<temp->y<<") ";
}
temp=temp->next;
}
if(!found)
cout<<"Not Found";
cout<<"\n";
}

bool Search(int x,int y){
struct Node* temp=head;
while(temp){
if(x==temp->x&&y==temp->y)
return true;
temp=temp->next;
}
return false;
}

int Length(){
int ctr=0;
struct Node* temp=head;
while(temp){
ctr++;
temp=temp->next;
}
return ctr;
}

void Del(int x,int y){
if(Search(x,y)){
	struct Node *temp=head,*prev=NULL;
	while(temp){
		if(temp->x==x&&temp->y==y)
		{
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
cout<<"0\n";
}
else cout<<"-1\n";
}
    int main()
    {
        //IOS
	head=NULL;
	int t;
	cin>>t;
	while(t--){
		int f;
		cin>>f;
		if(f==1){
			int x,y;
			cin>>x>>y;
			AddFirst(x,y);
		}
		else if(f==2){
			DelFirst();
		}
		else if(f==3){
			int x,y;
			cin>>x>>y;
			Del(x,y);
		}
		else if(f==4){
			float d;
			cin>>d;
			Search(d);
		}
		else if(f==5)
		{
			int x,y;
			cin>>x>>y;
			if(Search(x,y))
				cout<<"Found\n";
			else cout<<"Not Found\n";
		}
		else
			cout<<Length()<<"\n";
	}
	return 0;
    }









