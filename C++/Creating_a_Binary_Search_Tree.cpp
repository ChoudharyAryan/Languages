#include <iostream>
#include <climits>
using namespace std;

struct  node{
    int data;
    node *left, *right;
    node(int val){
        data = val;
        left = NULL;
        right  = NULL;
    }
};


node* BinarySearchTree(node* n,int val){
	if (n==NULL)
	{
		return new node(val);
	}
	if (val < n->data)
	{
		n->left = BinarySearchTree(n->left,val);
	}
	if (val > n->data)
	{
		n->right = BinarySearchTree(n->right,val);
	}

	return n;
}

void inorder(node* n){
	if (n==NULL)
	{
		return;
	}

	inorder(n->left);
	cout<<n->data;
	inorder(n->right);
}


int main()
{
     node* n = NULL;
     n = BinarySearchTree(n,5);
     BinarySearchTree(n,1);
     BinarySearchTree(n,3);
     BinarySearchTree(n,4);		
     BinarySearchTree(n,2);
     BinarySearchTree(n,7);

     inorder(n);

   
    	
    return 0;
}