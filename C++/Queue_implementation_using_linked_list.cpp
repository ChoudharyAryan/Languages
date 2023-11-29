#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class queue
{
    node *f;
    node *b;

public:
    queue()
    {
        f = NULL;
        b = NULL;
    }
    void enqueue(int x)
    {
        node *n = new node(x);
        if (n == NULL)
        {
            cout << "overflow";
            return;
        }
        if (f == NULL)
        {
            f = n;
            b = n;
        }
        b->next = n;
        b = b->next;
    }

    void dequeue()
    {
        if (f == NULL)
        {
            cout << "underflow";
            return;
        }
        node *del = f;
        f = f->next;
        delete del;
    }

    int peek()
    {
        if (f == NULL)
        {
            cout << "underflow";
            return -1;
        }
        return f->data;
    }

    bool empty()
    {
        if (f == NULL)
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
    // qe.dequeue();
    // qe.dequeue();
    display(qe);

    return 0;
}
