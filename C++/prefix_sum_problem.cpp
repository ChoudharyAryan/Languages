#include <iostream>
using namespace std;
void prefixsum(int arr[], int l);

int main()
{
    int arr[5] = {10, 20, 10, 5, 15};
    prefixsum(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i]<<" ";
    }

    return 0;
}

void prefixsum(int arr[], int l)
{
    for (int i = 1; i < l; i++)
    {
        arr[i] = arr[i] + arr[i - 1];
    }
}
