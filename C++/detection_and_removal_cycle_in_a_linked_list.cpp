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

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
};

void makecycle(node *&head, int pos)
{
    node *temp = head;
    node *newhead;

    int count = 1;
    while (temp->next != NULL)
    {
        if (count == pos)
        {
            newhead = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = newhead;
}

bool detection(node *head)
{
    node *fast = head;
    node *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            return true;
        }
    }

    return false;
}

void removecycle(node *&head)
{
    node *fast = head;
    node *slow = head;

    do
    {
        fast = fast->next->next;
        slow = slow->next;
    } while (fast != slow);

    fast = head;
    while (fast->next != slow->next)
    {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = NULL;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    insertAtTail(head, 8);
    insertAtTail(head, 9);
    insertAtTail(head, 10);
    insertAtTail(head, 11);
    insertAtTail(head, 12);
    insertAtTail(head, 13);
    insertAtTail(head, 14);
    makecycle(head, 1);
    cout << detection(head) << endl;
    removecycle(head);
    cout << detection(head) << endl;
    display(head);

    return 0;
}