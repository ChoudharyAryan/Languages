#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> dq;
    // dq.push_back(2);
    dq.push_front(1);
    dq.push_front(2);
    dq.push_back(3);
    // dq.pop_front();

    cout << dq.front() << endl;
    cout << dq.back() << endl;
    cout << dq.size();
    return 0;
}
