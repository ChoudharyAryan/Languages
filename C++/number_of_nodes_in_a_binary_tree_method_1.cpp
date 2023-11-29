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
    queue<node *> q;
    int k = 0;
    q.push(n);
    while (!q.empty())
    {
        int l = q.size();
        for (int i = 0; i < l; i++)
        {
            if (q.front()->left)
            {
                q.push(q.front()->left);
            }
            if (q.front()->right)
            {
                q.push(q.front()->right);
            }
            q.pop();
        }
        k++;
    }

    return pow(2, k) - 1;
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