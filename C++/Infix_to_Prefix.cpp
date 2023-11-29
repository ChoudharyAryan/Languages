#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int prec(char c)
{
    if (c == '^')
    {
        return 3;
    }
    if (c == '/' || c == '*')
    {
        return 2;
    }
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
string infixtoprefix(string s)
{
    reverse(s.begin(), s.end());
    stack<char> st;
    string res;

    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '(')
        {
            s[i] = ')';
        }
        else if (s[i] == ')')
        {
            s[i] = '(';
        }
        i++;
    }

    i = 0;
    while (s[i] != '\0')
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            res += s[i];
        }

        if (s[i] == '(')
        {
            st.push(s[i]);
        }
        if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && prec(st.top()) >= prec(s[i]))
            {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }

    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    string s = "(a-b/c)*(a/k-l)";
    cout << infixtoprefix(s);
 
}
