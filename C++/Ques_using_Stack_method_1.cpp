#include <iostream>
#include <stack>
using namespace std;

class queue
{
    stack<int> s1;
    stack<int> s2;

public:
    void enqueue(int x)
    {
        s1.push(x);
    }

    void dequeue()
    {
        if (s1.empty() and s2.empty())
        {
            cout << "nothing t0 pop";
            return;
        }
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
    }

    int peek()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "empty Queue";
            return -1;
        }
        if (s1.empty())
        {
            while (!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
            return s1.top();
        }
        return s1.top();
    }

    bool empty()
    {
        if (s1.empty() && s2.empty())
        {
            return true;
        }
        return false;
    }

    void display()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "empty Queue";
            return;
        }

        if (s1.empty())
        {
            while (!s2.empty())
            {
                cout << s2.top();
                s2.pop();
            }
        }

        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        while (!s2.empty())
        {
            cout << s2.top();
            s2.pop();
        }
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
    // qe.dequeue();
    qe.display();

    return 0;
}
