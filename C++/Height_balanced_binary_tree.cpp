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

bool balancedTree(node *n, int *height)
{
    if (n == NULL)
    {
        return true;
    }
    int lh = 0, rh = 0;

    if (balancedTree(n->left, &lh) == false)
    {
        return false;
    }
    if (balancedTree(n->right, &rh) == false)
    {
        return false;
    }

    *height = max(lh, rh) + 1;

    if (abs(lh - rh) <= 1)
    {

        return true;
    }
    else
    {
        return false;
    }
}

void preorderT(node *n)
{
    if (n == NULL)
    {
        return;
    }

    cout << n->data << endl;
    preorderT(n->left);
    preorderT(n->right);
}

int main()
{
    node *n = new node(1);
    n->left = new node(2);
    n->right = new node(3);
    n->left->left = new node(4);
    n->left->left->right = new node(4);
    int height = 0;

    cout << balancedTree(n, &height);
}