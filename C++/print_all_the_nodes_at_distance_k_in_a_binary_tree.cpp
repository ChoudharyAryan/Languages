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

void nodesInTheDistance(node *n, int k)
{
    if (n == NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout << n->data;
    }

    nodesInTheDistance(n->left, k - 1);
    nodesInTheDistance(n->right, k - 1);
}

int printNodeAtk(node *n, node *f, int k)
{
    if (n == NULL)
    {
        return -1;
    }
    if (n == f)
    {
        nodesInTheDistance(n, k);
        return 0;
    }
    int dl = printNodeAtk(n->left, f, k);
    if (dl != -1)
    {
        if (dl + 1 == k)
        {
            cout << n->data;
        }
        else
        {
            nodesInTheDistance(n->right, k - dl - 2);
        }
        return 1 + dl;
    }

    int dr = printNodeAtk(n->right, f, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
        {
            cout << n->data;
        }
        else
        {
            nodesInTheDistance(n->left, k - dr - 2);
        }
        return 1 + dr;
    }

    return -1;
}

int main()
{
    node *n = new node(1);
    n->left = new node(5);
    n->left->left = new node(6);
    n->left->left->right = new node(7);
    n->left->left->right->right = new node(9);
    n->left->left->right->left = new node(8);
    n->right = new node(2);
    n->right->right = new node(4);
    n->right->left = new node(3);
    printNodeAtk(n, n->left, 3);

    return 0;
}
