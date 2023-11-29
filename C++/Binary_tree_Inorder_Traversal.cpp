#include <iostream>
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

void InorderT(node *n)
{
    if (n == NULL)
    {
        return;
    }

    InorderT(n->left);
    cout << n->data << endl;
    InorderT(n->right);
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
    InorderT(n);
}