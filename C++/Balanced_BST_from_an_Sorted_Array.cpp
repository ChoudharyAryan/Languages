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

node* BalancedBSTfromSortedArray(int array[],int st,int en){
	
	if (st > en)
	{
		return NULL;
	}
	int mid = (st+en)/2;	
	node* n = new node(array[mid]);
	n->left = BalancedBSTfromSortedArray(array,st,mid-1);
	n->right= BalancedBSTfromSortedArray(array,mid+1,en);
	return n;
}

void preorder(node* n){
	if (n==NULL)
	{
		return;
	}

	cout<<n->data<<" ";
	preorder(n->left);	
	preorder(n->right);
}


int main()
{
	int array[] = {10,20,30,40,50};
	node* n = BalancedBSTfromSortedArray(array,0,4);
	preorder(n);

    	
    return 0;
	
	
	
}