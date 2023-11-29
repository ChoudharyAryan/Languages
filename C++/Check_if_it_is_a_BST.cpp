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

bool isBST(node* n,node* min,node* max){
	if (n==NULL)
	{
		return true;
	}
	if (min!= NULL && n->data <= min->data)
	{
		return false;
	}
	if (max!= NULL && n->data >= max->data)
	{
		return false;
	}
	bool lv = isBST(n->left,min,n);
	bool rv = isBST(n->right,n,max);
	
	return lv and rv;
}


int main()
{
	 node *n = new node(1);
    n->left = new node(5);
    n->left->left = new node(6);
    n->left->left->right = new node(7);
    n->left->left->right->right = new node(9);
    n->left->left->right->left = new node(8);
    n->right = new node(2);
    n->right->right = new node(4);
    n->right->left = new node(3);    
	if(isBST(n,NULL,NULL)){
		cout<<"a valid BST";
	}else{
		cout<<"invalid BST";
	}
    	
    return 0;
	
	
	
}