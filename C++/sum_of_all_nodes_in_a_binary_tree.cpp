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
    if (n == NULL)
    {
        return -1;
    }

    static int k = 0;
    k += n->data;
    countNods(n->left);
    countNods(n->right);

    return k;
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
    cout << countNods(n);
}