#include <iostream>
#include <climits>
#include <vector>
using namespace std;

class node{
public:
	int data;
	node* right;
	node* left;

	node(int val){
		data = val;
		right = NULL;
		left = NULL;
	}
};

int catalan(int n,vector<int> &dp){
	if (n <= 1)
	{
		return 1;
	}
	if (dp[n] != -1)
	{
		return dp[n];
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		ans+=catalan(i-1,dp)*catalan(n-i,dp);
	}
	return dp[n]=ans;
}


void preorder(node* n){
     if (n==NULL)
     {
     	return;
     }
     cout<<n->data;
     preorder(n->left);
     preorder(n->right);
}

int main()
{
	vector<int> dp(4,-1);
    cout<<catalan(3,dp);

    	
    return 0;
	
	
	
}