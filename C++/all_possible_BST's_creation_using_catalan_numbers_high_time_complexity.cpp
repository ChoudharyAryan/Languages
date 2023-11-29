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

vector<node*> possibleBst(int st,int en){
	vector<node*> tree;
	if (st>en)
	{
		tree.push_back(NULL);
		return tree;
	}
	for (int i = st; i <= en; ++i)
	{
		vector<node*> leftSubTree = possibleBst(st,i-1);
		vector<node*> rightSubTree = possibleBst(i+1,en);

		for (int j = 0; j < leftSubTree.size(); ++j)
		{
			node* left = leftSubTree[j];
			for (int k = 0; k < rightSubTree.size(); ++k)
			{
				node* right = rightSubTree[k];
				node* n = new node(i);
				n->right = right;
				n->left = left;
				tree.push_back(n);
			}
		}
		
	}
	return tree;
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
	vector<node*> arr = possibleBst(1,10);
	for (int i = 0; i < arr.size(); ++i)
	{
		cout<<i+1<<" ";
		preorder(arr[i]);
		cout<<endl;
	}
	
    	
    return 0;
	
	
	
}