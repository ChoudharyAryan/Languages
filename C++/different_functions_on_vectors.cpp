#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);
    a.push_back(8);
    a.push_back(9);
    a.push_back(1);
    a.push_back(2);
    for (auto i = a.begin(); i != a.cend(); ++i)
    {
        cout << *i << " ";
    }
    cout << a.size() << " ";
    cout << a.max_size() << " ";
    cout << a.capacity() << endl;
    a.shrink_to_fit();
    for (auto i = a.begin(); i != a.cend(); ++i)
    {
        cout << *i << " ";
    }
    cout << a.size() << " ";
    cout << a.max_size() << " ";
    cout << a.capacity() << " ";

    cout << a.at(2) << endl;
    int *pos = a.data();
    cout << *pos;
    a.assign(10, 99);
    for (auto i = a.begin(); i != a.cend(); ++i)
    {
        cout << *i << " ";
    }
    return 0;
}
