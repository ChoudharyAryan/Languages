#include <iostream>
#include <vector>
using namespace std;

class node
{
public:
    int data;
    node *right;
    node *left;

    node(int val)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
};

void flattenTheTree(node *&n)
{
    if (n == NULL)
    {
        return;
    }

    flattenTheTree(n->left);
    node *l = n->left;
    flattenTheTree(n->right);
    node *r = n->right;
    if (l == NULL)
    {
        return;
    }

    n->right = l;
    n->left = NULL;
    while (l->right != NULL)
    {
        l = l->right;
    }
    l->right = r;
}

void inorderPrint(node *n)
{
    if (n == NULL)
    {
        return;
    }
    inorderPrint(n->left);
    cout << n->data;
    inorderPrint(n->right);
}

int main()
{
    node *n = new node(4);
    n->left = new node(9);
    n->left->left = new node(1);
    n->left->right = new node(3);
    n->right = new node(5);
    n->right->right = new node(6);

    flattenTheTree(n);
    inorderPrint(n);

    return 0;
}
