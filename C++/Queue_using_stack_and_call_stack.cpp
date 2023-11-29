#include <iostream>
#include <stack>
using namespace std;

class queue
{
    stack<int> s1;

public:
    void enqueue(int x)
    {
        s1.push(x);
    }

    void dequeue()
    {
        if (s1.size() == 1)
        {
            s1.pop();
            return;
        }

        if (s1.empty())
        {
            cout << "empty Queue";
            return;
        }
        int k = s1.top();
        s1.pop();
        dequeue();
        s1.push(k);
    }

    int peek()
    {
        if (s1.size() == 1)
        {
            return s1.top();
        }

        if (s1.empty())
        {
            cout << "empty Queue";
            return -1;
        }
        int k = s1.top();
        s1.pop();
        dequeue();
        s1.push(k);
    }

    bool empty()
    {
        if (s1.empty())
        {
            return true;
        }
        return false;
    }

    void display()
    {
        if (s1.size() == 1)
        {
            cout << s1.top();
            return;
        }
        if (s1.empty())
        {
            cout << "empty Queue";
            return;
        }
        int k = s1.top();
        s1.pop();
        display();
        cout << k;
    }
};

int main()
{
    queue qe;
    qe.enqueue(1);
    qe.enqueue(2);
    qe.enqueue(3);
    qe.enqueue(4);
    qe.enqueue(5);
    qe.enqueue(6);
    qe.enqueue(7);
    // qe.dequeue();
    qe.dequeue();
    qe.display();

    return 0;
}
