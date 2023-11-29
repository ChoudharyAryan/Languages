#include <iostream>
using namespace std;
#define n 100
class stack
{
    string *arr;
    int top;

public:
    stack()
    {
        arr = new string[n];
        top = -1;
    }
    void push(string x)
    {
        if (top == n - 1)
        {
            cout << "Stack Overflow";
            return;
        }
        top++;
        arr[top] = x;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is alredy Empty";
            return;
        }
        top--;
    }

    string Top()
    {
        if (top == -1)
        {
            cout << "Empty Stack";
            return "-1";
        }
        return arr[top];
    }

    bool empty()
    {
        return top == -1;
    }
};

int main()
{
    stack st;
    st.push("hey,");
    st.push("how");
    st.push("are");
    st.push("you");
    st.push("doing");
    while (st.Top() != "-1")
    {
        cout << st.Top() << " ";
        st.pop();
    }

    return 0;
}
