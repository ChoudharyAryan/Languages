#include <iostream>
#include <vector>
using namespace std;
int stockSpan(vector<int> arr, int k)
{
    int n = arr.size();
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
    {
        int ig = arr[i];
        int j = i;
        while (arr[j] <= ig)
        {
            a[i]++;
            j--;
        }
    }
    return a[k - 1];
}

int main()
{
    vector<int> arr = {100, 80, 60, 70, 60, 75, 85};
    cout << stockSpan(arr, 6);

    return 0;
}
