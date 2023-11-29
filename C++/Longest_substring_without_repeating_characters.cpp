#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int mac(string arr)
{
    int n = arr.size();
    vector<int> a(130);
    queue<int> q;
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        if (a[arr[i]] == 0)
        {
            q.push(i);
            a[arr[i]]++;
        }
        else
        {
            while (a[arr[i]] != 0)
            {
                a[arr[q.front()]]--;
                q.pop();
                count++;
            }
            q.push(i);
            m = max(m, count);
        }
    }

    n = q.size();
    return max(n, m);
}

int main()
{
    string arr = "abba";
    cout << mac(arr);

    return 0;
}
