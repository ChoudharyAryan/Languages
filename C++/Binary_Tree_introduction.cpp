#include <iostream>

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int main()
{
    node *n = new node(1);
    n->left = new node(2);
    n->right = new node(3);
    n->left->left = new node(4);
    n->left->right = new node(5);
}

// 
//          1 
//         / \
//        2   3
//      /  \
//     4    5
// 
//  A Binary Tree.


// Properties of Binary Tree:
// 1. Maximum nodes at level L : 2^L
// 2. Maximum nodes in a tree of height H: *2^H-1*, where H is the number of levels
// 3. For N nodes, minimum possible height or minimum number of levels are log2(N+1)
// 4. A binary tree with L leaves has at least log2(N+1)+1 number of levels

