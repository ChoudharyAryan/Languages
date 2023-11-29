#include <iostream>
#include <climits>
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


node* preorderBST(int preorder[],int* preorderidx,int key,int min,int max,int n){
	if (*preorderidx >= n)
	{
		return NULL;
	}
	node* root = NULL;
	if (key > min && key < max)
	{
		root = new node(key);
		*preorderidx += 1;

		if (*preorderidx < n)
		{
			root->left = preorderBST(preorder,preorderidx,preorder[*preorderidx],min,key,n);
		}
		if (*preorderidx < n)
		{
			root->right = preorderBST(preorder,preorderidx,preorder[*preorderidx],key,max,n);
		}
	}	
	return root;
}


void preorderprint(node* n){
	if (n==NULL)
	{
		return;
	}
	

	cout<<n->data<<" ";
	preorderprint(n->left);
	preorderprint(n->right);
}



int main()
{
	 int preorder[] = {7,6,8,9};
	 int n =5;
	 int preorderidx = 0;
	 node* root = preorderBST(preorder,&preorderidx,preorder[0],INT_MIN,INT_MAX,4);
	 preorderprint(root);  
    	
    return 0;
}