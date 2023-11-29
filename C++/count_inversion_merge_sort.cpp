#include <iostream>
using namespace std;
int mergesort(int arr[], int l, int r);
int merge(int arr[], int l, int mid, int r);

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << mergesort(arr, 0, n - 1) << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }

    return 0;
}

int mergesort(int arr[], int l, int r)
{
    int inv = 0;
    if (l < r)
    {
        int mid = (r + l) / 2;
        inv += mergesort(arr, l, mid);
        inv += mergesort(arr, mid + 1, r);

        inv += merge(arr, l, mid, r);
    }
    return inv;
}

int merge(int arr[], int l, int mid, int r)
{
    int inv = 0;
    int n1, n2;
    n1 = mid - l + 1;
    n2 = r - mid;
    int a[n1];
    int b[n2];
    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid + i + 1];
    }
    int i, j, k;
    i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (a[i] > b[j])
        {
            arr[k] = b[j];
            k++, j++;
            inv += n1 - i;
        }
        else
        {
            arr[k] = a[i];
            k++, i++;
        }
    }

    while (i < n1)
    {
        arr[k] = a[i];
        k++, i++;
    }

    while (j < n2)
    {
        arr[k] = b[j];
        k++, j++;
    }
    return inv;
}