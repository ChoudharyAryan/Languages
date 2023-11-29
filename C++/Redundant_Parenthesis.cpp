#include <iostream>
#include <vector>
using namespace std;
int extraplayer(vector<char> arr)
{
    int s, e;
    s = 0, e = 0;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        while (i < arr.size() - 1 && arr[i] == '(' && arr[i + 1] == '(')
        {
            s++;
            i++;
        }
        while (i < arr.size() - 1 && arr[i] == ')' && arr[i + 1] == ')')
        {
            e++;
            i++;
        }
        i++;
    }

    if (s == e)
    {
        return e;
    }
    else
    {
        s = max(s, e);
        e = min(s, e);
        return s - e;
    }
}

int main()
{
    vector<char> arr = {'(', '(', 'a', '+', 'b', ')', ')', '-', '(', 'b', ')'};
    cout << extraplayer(arr);
    return 0;
}
