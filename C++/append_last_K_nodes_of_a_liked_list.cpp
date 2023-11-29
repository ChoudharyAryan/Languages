#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *previous;

    node(int val)
    {
        data = val;
        next = NULL;
        previous = NULL;
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
    n->previous = temp;
};

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    n->previous = head->previous;
    if (head != NULL)
    {
        head->previous = n;
    }

    head = n;
}

void deleteAtHead(node *&head)
{
    node *temp = head;
    temp->next->previous = NULL;
    head = temp->next;
    delete temp;
}

void deletion(node *&head, int val)
{

    if (head->data == val)
    {

        deleteAtHead(head);
        return;
    }

    node *temp = head;
    while (temp->data != val)
    {
        temp = temp->next;
    }
    temp->previous->next = temp->next;

    if (temp->next != NULL)
    {
        temp->next->previous = temp->previous;
    }

    delete temp;
}

int length(node *head)
{
    int count = 0;
    while (head != NULL)
    {
        head = head->next;
        count++;
    }
    return count;
}

node *appendk(node *&head, int k)
{
    int l = length(head);
    if (head == NULL || k == 0 || k > l)
    {
        return head;
    }

    node *newHead;
    node *newTail;
    node *temp = head;
    int count = 1;

    while (temp->next != NULL)
    {
        if (count == l - k)
        {
            newTail = temp;
            newHead = temp->next;
        }
        temp = temp->next;
        count++;
    }
    temp->next = head;

    head = newHead;
    newTail->next = NULL;
    return head;
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
    appendk(head, 3);
    display(head);
}