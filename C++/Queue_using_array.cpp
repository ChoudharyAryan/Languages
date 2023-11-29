#include <iostream>
using namespace std;
#define n 100
class queue
{
    int *arr;
    int f;
    int b;

public:
    queue()
    {
        arr = new int[n];
        f = -1;
        b = -1;
    }
    void enqueue(int x)
    {
        if (b == n - 1)
        {
            cout << "overflow";
            return;
        }
        if (f == -1)
        {
            f++;
        }

        b++;
        arr[b] = x;
    }

    void dequeue()
    {
        if (f == -1 || f > b)
        {
            cout << "underflow";
            return;
        }
        f++;
    }

    int peek()
    {
        if (f == -1 || f > b)
        {
            cout << "underflow";
            return -1;
        }
        return arr[f];
    }

    bool empty()
    {
        if (f == -1 || f > b)
        {
            return true;
        }
        return false;
    }
};

void display(queue qe)
{
    while (!qe.empty())
    {
        cout << qe.peek();
        qe.dequeue();
    }
}

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
    qe.dequeue();
    qe.dequeue();
    display(qe);

    return 0;
}
