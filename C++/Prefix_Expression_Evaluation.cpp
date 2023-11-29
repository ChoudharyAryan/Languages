#include <iostream>
#include <stack>
using namespace std;
int prefix(string s)
{
    stack<int> st;
    int n1, n2, n3;
    n1 = 0, n2 = 0, n3 = 0;
    int i = s.length() - 1;
    while (i >= 0)
    {
        if (isdigit(s[i]))
        {
            st.push(s[i] - '0');
        }
        else
        {
            n1 = st.top();
            st.pop();
            n2 = st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(n1 + n2);
                break;
            case '-':
                st.push(n1 - n2);
                break;
            case '*':
                st.push(n1 * n2);
                break;
            case '/':
                st.push(n1 / n2);
                break;
            case '^':
                st.push(n1 ^ n2);
                break;
            default:
                break;
            }
        }

        i--;
    }
    return st.top();
}

int main()
{
    string s = "-+7*45+20";
    cout << prefix(s);

    return 0;
}
