/* Author   : Vaibhav Kumar Singh
   Roll No. : 180101086           */

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

/*
 * Node Declaration
 */
struct node
{
    int user_id;
    int recharge;
    struct node *left;
    struct node *right;
}*root;

/*
 * Class Declaration
 */
class AVL_Tree
{
    public:
        int height(node *);
        int diff(node *);
        node *rr_rotation(node *);
        node *ll_rotation(node *);
        node *lr_rotation(node *);
        node *rl_rotation(node *);
        node* balance(node *);
        node* insert_node(node* ,int , int* );
        AVL_Tree()
        {
            root = nullptr;
        }
};

/*
 * Height of AVL Tree
 */
int AVL_Tree::height(node *temp)
{
    int h = 0;
    if (temp != nullptr)
    {
        int l_height = height (temp->left);
        int r_height = height (temp->right);
        int max_height = max (l_height, r_height);
        h = max_height + 1;
    }
    return h;
}

/*
 * Height Difference
 */
int AVL_Tree::diff(node *temp)
{
    int l_height = height (temp->left);
    int r_height = height (temp->right);
    int b_factor= l_height - r_height;
    return b_factor;
}

/*
 * Right- Right Rotation
 */
node *AVL_Tree::rr_rotation(node *parent)
{
    node *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}
/*
 * Left- Left Rotation
 */
node *AVL_Tree::ll_rotation(node *parent)
{
    node *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

/*
 * Left - Right Rotation
 */
node *AVL_Tree::lr_rotation(node *parent)
{
    node *temp;
    temp = parent->left;
    parent->left = rr_rotation (temp);
    return ll_rotation (parent);
}

/*
 * Right- Left Rotation
 */
node *AVL_Tree::rl_rotation(node *parent)
{
    node *temp;
    temp = parent->right;
    parent->right = ll_rotation (temp);
    return rr_rotation (parent);
}

/*
 * Balancing AVL Tree
 */
node *AVL_Tree::balance(node *temp)
{
    int bal_factor = diff (temp);
    if (bal_factor > 1)
    {
        if (diff (temp->left) > 0)
            temp = ll_rotation (temp);
        else
            temp = lr_rotation (temp);
    }
    else if (bal_factor < -1)
    {
        if (diff (temp->right) > 0)
            temp = rl_rotation (temp);
        else
            temp = rr_rotation (temp);
    }
    return temp;
}

/*
 * Insert Element into the tree
 */
node* AVL_Tree::insert_node(node* root,int uid, int* rech)
{
    if (root == nullptr)
    {
        root = new node;
        root->user_id = uid;
        root->recharge = *rech;
        root->left = nullptr;
        root->right = nullptr;
        return root;
    }
    else if (uid < root->user_id)
    {
        root->left = insert_node(root->left, uid, rech);
        root = balance (root);
    }
    else if (uid > root->user_id)
    {
        root->right = insert_node(root->right, uid, rech);
        root = balance (root);
    }
    else{
        root->recharge+=*rech;
        *rech=root->recharge;
        return root;
    }
    return root;
}

int main()
{
    AVL_Tree avl;
	int n;
	cin>>n;
	int q;
	cin>>q;
	int maxi=-1;
	int id=-1;
	while(q--){
		int type;
		cin>>type;
		if(type==1){
			int uid;
			int amount;
			cin>>uid>>amount;
			root=avl.insert_node(root,uid,&amount);
			if(amount>maxi){
				maxi=amount;
				id=uid;
			}
		}
		else{
			if(id==-1)
				cout<<"No data available.\n";
			else
				cout<<id<<"\n";
		}
	}
    return 0;
}

