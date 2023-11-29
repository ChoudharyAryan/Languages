#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

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

int diameterofTree(node *n, int *height)
{
    if (n == NULL)
    {
        *height = 0;
        return 0;
    }

    int lh = 0, rh = 0;
    int ld = diameterofTree(n->left, &lh);
    int rd = diameterofTree(n->right, &rh);
    int currntDiameter = lh + rh + 1;
    *height = max(lh, rh) + 1;

    return max(currntDiameter, max(ld, rd));
}

int main()
{
    node *n = new node(1);
    n->left = new node(2);
    n->right = new node(3);
    n->left->left = new node(4);
    n->left->right = new node(5);
    n->right->left = new node(6);
    n->right->right = new node(7);
    n->left->right->left = new node(2);
    n->left->right->left->left = new node(3);
    n->left->right->left->right = new node(5);
    n->right->left->right = new node(6);
    n->right->left->right->right = new node(7);
    int hieght = 0;
    cout << diameterofTree(n, &hieght) << endl;
}