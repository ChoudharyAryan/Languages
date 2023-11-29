#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int largestRectangle(vector<int> arr)
{
    arr.push_back(0);
    int n = arr.size();
    stack<int> st;
    int i = 0;
    int ans = 0;
    while (i < n)
    {
        while (!st.empty() && arr[i] < arr[st.top()])
        {
            int tp = st.top();
            st.pop();

            ans = max(ans, arr[tp] * (st.empty() ? i : i - st.top() - 1));
        }
        st.push(i);
        i++;
    }
    return ans;
}

int main()
{
    vector<int> a = {2, 1, 5, 6, 2, 3, 2, 2, 2, 2};
    cout << largestRectangle(a);

    return 0;
}
