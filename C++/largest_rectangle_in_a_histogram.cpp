
// Solution of Brute Force approach

#include <iostream>

#include <vector>

using namespace std;

int main()

{

    vector<int> a = {2, 1, 5, 6, 2, 3, 2, 2, 2, 2, 0};

    int ans = 0;

    int n = a.size();

    for (int i = 0; i < n; i++)

    {

        int minh = a[i];

        for (int j = i; j < n; j++)

        {

            minh = min(a[j], minh);

            int len = j - i + 1;

            ans = max(ans, len * minh);
        }
    }

    cout << ans;

    return 0;
}