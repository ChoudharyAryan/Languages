#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int trapingRainwater(vector<int> arr)
{
    stack<int> st;
    int ans = 0;
    int i = 0;
    while (i < arr.size())
    {
        while (!st.empty() && arr[i] > arr[st.top()])
        {
            int tp = st.top();
            st.pop();
            if (st.empty())
            {
                break;
            }
            int len = i - st.top() - 1;
            ans += (min(arr[i], arr[st.top()]) - arr[tp]) * len;
        }
        st.push(i++);
    }
    return ans;
}

int main()
{
    vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trapingRainwater(arr);

    return 0;
}
