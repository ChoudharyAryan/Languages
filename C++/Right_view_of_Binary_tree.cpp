#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
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

void levelOrder(node *n)
{
    if (n == NULL)
    {
        return;
    }

    queue<node *> q;
    q.push(n);

    while (!q.empty())
    {
        int n = q.size();
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            node *c = q.front();
            q.pop();
            if (c->left)
            {
                q.push(c->left);
            }
            if (c->right)
            {
                q.push(c->right);
            }
            k = c->data;
        }
        cout << k;
        cout
            << endl;
    }
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
    levelOrder(n);
}
