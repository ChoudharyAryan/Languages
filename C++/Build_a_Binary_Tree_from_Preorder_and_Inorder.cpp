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

int findpos(vector<int> inorder, int st, int en, int curr)
{
    for (int i = st; i <= en; i++)
    {
        if (inorder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}

node *BuildT(vector<int> preorder, vector<int> inorder, int st, int en)
{
    static int idx = 0;
    if (st > en)
    {
        return NULL;
    }

    int curr = preorder[idx];
    node *n = new node(preorder[idx++]);
    if (st == en)
    {
        return n;
    }
    int pos = findpos(inorder, st, en, curr);

    n->left = BuildT(preorder, inorder, st, pos - 1);
    n->right = BuildT(preorder, inorder, pos + 1, en);

    return n;
}

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
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
    vector<int> inorder = {4, 5, 2, 1, 6, 7, 3};
    node *n = BuildT(preorder, inorder, 0, 6);
    InorderT(n);
}
