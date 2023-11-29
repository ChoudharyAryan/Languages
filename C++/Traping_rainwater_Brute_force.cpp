#include <iostream>
#include <vector>
using namespace std;
int rain(vector<int> arr)
{
    int n = arr.size();
    if (n<=2)
    {
        return -1;
        //water storge not possible.
    }
    
    vector<int> rightmax(n);
    vector<int> leftmax(n);
    leftmax[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        leftmax[i] = max(leftmax[i - 1], arr[i]);
    }
    rightmax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        rightmax[i] = max(rightmax[i + 1], arr[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (min(leftmax[i], rightmax[i]) - arr[i]);
    }
    return ans;
}

int main()
{
    vector<int> a = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << rain(a);

    return 0;
}
