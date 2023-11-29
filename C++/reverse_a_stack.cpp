#include <iostream>
#include <stack>
using namespace std;
stack<int> insertAtBottom(stack<int> &st, int s);
void reverse(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }

    int s = st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st, s);
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
}

stack<int> insertAtBottom(stack<int> &st, int s)
{
    if (st.empty())
    {
        st.push(s);
        return st;
    }

    st.pop();
    return insertAtBottom(st, s);
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    reverse(st);

    return 0;
}
