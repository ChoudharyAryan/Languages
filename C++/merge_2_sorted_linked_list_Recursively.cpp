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

node *mergeRecursive(node *head, node *haed)
{

    if (head == NULL)
    {
        return haed;
    }
    if (haed == NULL)
    {
        return head;
    }

    node *result;
    if (head->data > haed->data)
    {
        result = haed;
        result->next = mergeRecursive(head, haed->next);
    }
    if (head->data < haed->data)
    {
        result = head;
        result->next = mergeRecursive(head->next, haed);
    }
    return result;
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
    node *haed = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(haed, 7);
    insertAtTail(haed, 8);
    insertAtTail(haed, 9);
    insertAtTail(haed, 10);
    insertAtTail(haed, 11);
    insertAtTail(haed, 12);
    display(head);
    display(haed);
    head = mergeRecursive(head, haed);
    display(head);
}