#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> threesum(vector<int> arr, int x)
{
    sort(arr.begin(), arr.end());
    vector<int> ans;
    int n1, n2, n3;
    for (int i = 0; i < arr.size(); i++)
    {
        n1 = i;
        n2 = i + 1;
        n3 = arr.size() - 1;
        while (n2 != n3)
        {
            if (n1 < 0 || n3 >= arr.size())
            {
                // Bounds check to avoid segmentation fault
                break;
            }
            if (x - arr[n1] == arr[n2] + arr[n3])
            {
                return ans = {arr[n1], arr[n2], arr[n3]};
            }
            if (x - arr[n1] < arr[n2] + arr[n3])
            {
                n3--;
            }
            if (x - arr[n1] > arr[n2] + arr[n3])
            {
                n2++;
            }
        }
    }
    return {};
}

int main()
{
    vector<int> arr = {1, 3, 6, 7, 9, 12};
    vector<int> res = threesum(arr, 100);
    if (res.empty())
    {
        cout << "-1";
        return 0;
    }

    for (auto i : res)
    {
        cout << i << " ";
    }

    return 0;
}
