#include <iostream>
#include <stack>
using namespace std;
bool balanced(string s)
{
    stack<char> st;
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st.push(s[i]);
        }
        else
        {
            switch (s[i])
            {
            case ')':
                if (!st.empty() && st.top() == '(')
                {
                    st.pop();
                }

                break;
            case '}':
                if (!st.empty() && st.top() == '{')
                {
                    st.pop();
                }

                break;
            case ']':
                if (!st.empty() && st.top() == '[')
                {
                    st.pop();
                }

                break;

            default:
                break;
            }
        }
        i++;
    }
    if (st.empty())
    {
        return true;
    }
    return false;
}

int main()
{
    string s = "({[])";
    cout << balanced(s);

    return 0;
}
