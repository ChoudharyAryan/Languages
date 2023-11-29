#include <iostream>
#include <stack>
using namespace std;
void reverse(string s)
{
    int i = 0;
    stack<string> st;
    string words = "";
    while (i <= s.length())
    {
        if (s[i] == ' ' || s[i]=='\0')
        {
            st.push(words);
            words = "";
            i++;
        }
        words += s[i];
        i++;
    }

    while (!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

int main()
{
    string s = "Hi, how are you doing";
    reverse(s);
    return 0;
}
