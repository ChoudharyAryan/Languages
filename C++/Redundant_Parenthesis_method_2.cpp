#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int extraplayer(string s)
{
    int ans = 0;
    int n = s.size();
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (st.empty())
            {
                ans++;
            }
            else if (st.top() == '(')
            {
                ans++;
                st.pop();
            }
            else if (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/')
            {
                while (st.top() != '(')
                {
                    st.pop();
                    if (st.empty())
                    {
                        ans++;
                        break;
                    }
                }
                if (st.top() == '(')
                {
                    st.pop();
                }
            }
        }
        i++;
    }
    return ans;
}

int main()
{
    string s = "((a+b))-(b)";
    cout << extraplayer(s);

    return 0;
}
