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

int KthLevelSum(node *n, int k)
{
    if (n == NULL)
    {
        return -1;
    }

    queue<node *> q;
    int l = 0;
    int sum = 0;
    q.push(n);
    q.push(NULL);
    while (!q.empty())
    {

        node *n = q.front();
        q.pop();
        if (n != NULL)
        {
            if (n->left)
            {
                q.push(n->left);
            }
            if (n->right)
            {
                q.push(n->right);
            }
            cout << n->data;
            if (l == k)
            {
                sum += n->data;
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
            l++;
            cout << endl;
        }
    }
    cout << endl;
    return sum;
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
    cout << KthLevelSum(n, 3);
}
