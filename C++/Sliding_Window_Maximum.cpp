#include <iostream>
#include <deque>
#include <vector>
using namespace std;
vector<int> maximumWindow(vector<int> &dq, int k)
{
    vector<int> ans;
    deque<int> index;
    int i = 0;
    while (i < dq.size())
    {
        if (!index.empty() && index.front() == i - k)
        {
            index.pop_front();
        }
        while (!index.empty() && dq[index.back()] < dq[i])
        {
            index.pop_back();
        }
        index.push_back(i);
        if (i >= k - 1)
        {
            ans.push_back(dq[index.front()]);
        }
        i++;
    }
    return ans;
}

int main()
{
    vector<int> dq = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    vector<int> ans = maximumWindow(dq, 3);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
