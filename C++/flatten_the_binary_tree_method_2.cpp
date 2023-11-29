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
    if (n == NULL || n->right == NULL && n->left == NULL)
    {
        return;
    }

    if (n->left != NULL)
    {
        flattenTheTree(n->left);
        node *temp = n->right;
        n->right = n->left;
        n->left = NULL;
        node *t = n;
        while (t->right != NULL)
        {
            t = t->right;
        }
        t->right = temp;
    }
    flattenTheTree(n->right);
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
