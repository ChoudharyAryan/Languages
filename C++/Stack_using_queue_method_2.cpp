#include <iostream>
#include <queue>
using namespace std;
class stack
{
    int N;
    queue<int> q1;
    queue<int> q2;

public:
    stack()
    {
        N = 0;
    }

    void push(int x)
    {
        q1.push(x);
        N++;
    }

    void pop()
    {
        if (q1.empty())
        {
            cout << "underflow";
            return;
        }

        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        q1.swap(q2);
    }

    int top()
    {
        if (q1.empty())
        {
            cout << "underflow";
            return -1;
        }

        return q1.back();
    }

    bool empty()
    {
        return q1.empty();
    }
};

int main()
{

    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;

    return 0;
}
