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

class stack
{
    node *top;

public:
    stack()
    {
        top = NULL;
    }
    void *push(int val)
    {
        node *n = new node(val);
        if (n == NULL)
        {
            cout << "Stack Overflow" << endl;
            exit(1);
        }
        n->data = val;
        n->next = top;
        top = n;
    }

    bool isempty()
    {
        return top == NULL;
    }

    int Top()
    {
        if (top == NULL)
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return top->data;
    }

    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        node *temp;
        temp = top;
        top = top->next;
        delete temp;
    }

    void display()
    {
        node *temp;

        // Check for stack underflow
        if (top == NULL)
        {
            cout << "\nStack Underflow";
            exit(1);
        }
        else
        {
            temp = top;
            while (temp != NULL)
            {

                // Print node data
                cout << temp->data;

                // Assign temp link to temp
                temp = temp->next;
                if (temp != NULL)
                    cout << " -> ";
            }
        }
    }
};

int main()
{
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.display();

    return 0;
}
