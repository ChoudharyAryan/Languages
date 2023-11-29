#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int largestrectangle(vector<int> arr)
{
    arr.push_back(0);
    int n = arr.size();
    stack<int> st;
    int i = 0;
    int ans = 0;
    int top = 0;
    while (i < n)
    {
        if (st.empty() || arr[st.top()] < arr[i])
        {
            st.push(i++);
        }
        else
        {
            top = st.top();
            st.pop();
            ans = max(ans, arr[top] * (st.empty() ? i : i - st.top() - 1));
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {2, 1, 5, 6, 2, 3};
    cout << largestrectangle(arr);
    return 0;
}
