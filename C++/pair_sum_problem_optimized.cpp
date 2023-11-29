#include <iostream>
using namespace std;
bool prefixsum(int arr[], int l, int k);

int main()
{
    int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << prefixsum(arr, 8, 12);

    return 0;
}

bool prefixsum(int arr[], int l, int k)
{
    int n = 0;
    int m = l - 1;
    for (int i = 0; i < l; i++)
    {
        if (arr[n] + arr[m] > k)
        {
            m--;
        }
        if (arr[n] + arr[m] < k)
        {
            n++;
        }
        else
        {
            return true;
        }
    }
    return false;
}
