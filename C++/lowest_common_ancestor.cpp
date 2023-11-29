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

node *LowestCommonAncestor(node *n, int k1, int k2)
{
    if (n == NULL)
    {
        return NULL;
    }
    if (n->data == k1 || n->data == k2)
    {
        return n;
    }
    node *leftLCA = LowestCommonAncestor(n->left, k1, k2);
    node *rightLCA = LowestCommonAncestor(n->right, k1, k2);
    if (leftLCA && rightLCA)
    {
        return n;
    }
    if (leftLCA)
    {
        return leftLCA;
    }
    return rightLCA;
}

int main()
{
    node *n = new node(1);
    n->left = new node(2);
    n->left->left = new node(4);
    n->right = new node(3);
    n->right->right = new node(6);
    n->right->left = new node(5);
    n->right->left->left = new node(7);
    int k1 = 7;
    int k2 = 6;
    node *s = LowestCommonAncestor(n, k1, k2);
    if (s == NULL || s->data == k1 || s->data == k2)
    {
        cout << "one or both nodes does not exist";
    }
    else
    {
        cout << s->data;
    }
}
