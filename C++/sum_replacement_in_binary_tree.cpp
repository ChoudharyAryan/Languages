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

void subTreeData(node *n)
{

    if (n == NULL)
    {
        return;
    }

    subTreeData(n->left);
    subTreeData(n->right);
    if (n->left != NULL)
    {
        n->data += n->left->data;
    }
    if (n->right != NULL)
    {
        n->data += n->right->data;
    }
}

// THIS FUNCTION ALSO DOES THE SAME THING WITH SAME TIME COMPLEXITY AND SPACE COMPLEXITY.
//  int sumreplacement(node *temp)
//  {
//      if (temp == NULL)
//          return 0;
//      temp->data += (sumreplacement(temp->left) + sumreplacement(temp->right));
//      return temp->data;
//  }

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
    n->left->right = new node(5);
    n->right->left = new node(6);
    n->right->right = new node(7);
    n->left->right->left = new node(2);
    n->left->right->left->left = new node(3);
    n->left->right->left->right = new node(5);
    n->right->left->right = new node(6);
    n->right->left->right->right = new node(7);
    preorderT(n);
    subTreeData(n);
    cout << endl;
    preorderT(n);
}