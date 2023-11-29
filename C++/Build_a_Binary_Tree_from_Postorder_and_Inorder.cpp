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

node *BuildT(vector<int> postorder, vector<int> inorder, int st, int en)
{
    static int idx = postorder.size() - 1;
    if (st > en)
    {
        return NULL;
    }

    int curr = postorder[idx];
    node *n = new node(postorder[idx--]);

    int pos = findpos(inorder, st, en, curr);
    if (st == en)
    {
        return n;
    }

    n->right = BuildT(postorder, inorder, pos + 1, en);
    n->left = BuildT(postorder, inorder, st, pos - 1);

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
    vector<int> postorder = {4, 2, 5, 3, 1};
    vector<int> inorder = {4, 2, 1, 5, 3};
    node *n = BuildT(postorder, inorder, 0, 4);
    InorderT(n);

    return 0;
}
