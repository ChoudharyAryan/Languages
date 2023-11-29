#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int maxone(vector<int> arr, int k)
{
    int n = arr.size();
    int t = 0;
    int m = 0;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        if (arr[i] == 1)
        {
            q.push(i);
        }
        else if (arr[i] == 0 && t < k)
        {
            q.push(i);
            t++;
        }
        else
        {
            while (t == k)
            {
                if (arr[q.front()] == 0)
                {
                    t--;
                }

                q.pop();
                count++;
            }
            q.push(i);
            t++;
            m = max(m, count);
        }
    }
    n = q.size();
    return max(m, n);
}
int main()
{
    vector<int> a = {1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1};
    cout << maxone(a, 2);

    return 0;
}
