#include <iostream>
#include <stack>
#include <math.h>
using namespace std;
int postfix(string s)
{
    stack<int> st;
    int n1, n2, n3;
    n1 = 0, n2 = 0, n3 = 0;
    int i = 0;
    while (i < s.length())
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
                st.push(n2 - n1);
                break;
            case '*':
                st.push(n1 * n2);
                break;
            case '/':
                st.push(n2 / n1);
                break;
            case '^':
                st.push(pow(n1, n2));
                break;
            default:
                break;
            }
        }

        i++;
    }
    return st.top();
}

int main()
{
    string s = "46+2/5*7+";
    cout << postfix(s) << endl;
    return 0;
}
