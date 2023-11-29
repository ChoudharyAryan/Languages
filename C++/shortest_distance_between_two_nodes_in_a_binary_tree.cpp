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

int shortestPath(node *n, int k1, int k2)
{
    n = LowestCommonAncestor(n, k1, k2);
    if (n == NULL || n->data == k1 || n->data == k2)
    {
        return -1;
    }
    node *temp = n;
    int d1 = 0, d2 = 0;
    while (temp != NULL)
    {
        if (temp->data == k1 || temp->data == k2)
        {
            break;
        }
        d1++;
        temp = temp->left;
    }
    temp = n;

    while (temp != NULL)
    {
        if (temp->data == k1 || temp->data == k2)
        {
            break;
        }
        d2++;
        temp = temp->right;
    }

    return d1 + d2;
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
    cout << shortestPath(n, 4, 6);
}
