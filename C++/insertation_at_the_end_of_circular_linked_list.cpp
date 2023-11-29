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

void makecircle(node *&head)
{
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
}

void insertincircle(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
    }

    node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }
    n->next = temp->next;
    temp->next = n;
}

void display(node *head)
{
    node *temp = head;
    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);

    cout << head->data << endl;
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
    insertAtTail(head, 7);
    insertAtTail(head, 8);
    insertAtTail(head, 9);
    insertAtTail(head, 10);
    insertAtTail(head, 11);
    insertAtTail(head, 12);
    makecircle(head);
    insertincircle(head, 13);
    display(head);
}