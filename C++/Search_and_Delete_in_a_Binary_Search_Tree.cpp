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

node* searchInBST(node* n,int k){
	if (n == NULL)
	{
		return NULL;
	}
	if (n->data == k)
	{
		return n;
	}

	if (k > n->data)
	{
		return searchInBST(n->right,k);
	}
	
	return searchInBST(n->left,k);
	
}

node* inorderSucessor(node* n){
	node* temp = n;
	while(temp && temp->left){
		temp = temp->left;
	}
	return temp;
}


node* deleteInBST(node* &n,int k){
	if (k > n->data ) 
	{
		n->right = deleteInBST(n->right,k);
	}
	else if (k < n->data)
	{
		n->left = deleteInBST(n->left,k);
	}else{
		if (n->left ==NULL)
		{
			node* temp = n->right;
			free(n);
			return temp;
		}
		else if (n->right == NULL)
		{
			node* temp = n->left;
			free(n);
			return temp;
		}else{
			node* temp = inorderSucessor(n->right);
			n->data = temp->data;
			n->right = deleteInBST(n->right,temp->data);
		}
		return n;
	}
	return n;
}


int main()
{
     node* n = NULL;
     n = BinarySearchTree(n,5);
     BinarySearchTree(n,1);
     BinarySearchTree(n,7);
     BinarySearchTree(n,3);		
     BinarySearchTree(n,4);
     BinarySearchTree(n,2);
     inorder(n);
     cout<<endl;
     n = deleteInBST(n,3);
     inorder(n);

    	
    return 0;
}