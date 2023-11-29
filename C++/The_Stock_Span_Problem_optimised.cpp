#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> stockSpan(vector<int> arr)
{
    vector<int> a;
    stack<pair<int, int>> st;
    int i = 0;

    while (i < arr.size())
    {
        int days = 1;
        while (!st.empty() && arr[i] >= st.top().first)
        {
            days += st.top().second;
            st.pop();
        }
        st.push(make_pair(arr[i], days));
        a.push_back(days);
        i++;
    }
    return a;
}

int main()
{
    vector<int> a = {100, 80, 60, 70, 60, 70, 75, 85};
    vector<int> res = stockSpan(a);
    for (auto i : res)
    {
        cout << i << " ";
    }

    return 0;
}
