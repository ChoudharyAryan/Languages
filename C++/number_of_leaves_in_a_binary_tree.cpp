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

int countNods(node *n)
{
    static int k = 0;
    if (n == NULL)
    {
        return 0;
    }

    countNods(n->left);
    if (n->left == NULL && n->right == NULL)
    {
        k++;
    }
    countNods(n->right);
    if (n->left == NULL && n->right == NULL)
    {
        k++;
    }

    return k / 2;
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
    cout << countNods(n);
}