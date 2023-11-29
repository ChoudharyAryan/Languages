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

void intersect(node *head, node *haed, int k)
{
    node *temp = head;
    int count = 1;
    while (count != k)
    {
        temp = temp->next;
        count++;
    }
    node *tmp = haed;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = temp;
}

int intersection(node *head, node *haed)
{
    int l = length(head);
    int m = length(haed);
    node *ptr1;
    node *ptr2;
    int count = 0;
    if (l > m)
    {
        count = l - m;
        ptr1 = head;
        ptr2 = haed;
    }
    else
    {
        count = m - l;
        ptr1 = haed;
        ptr2 = head;
    }

    while (count)
    {
        ptr1 = ptr1->next;
        count--;
    }

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return 0;
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
    intersect(head, haed, 3);
    cout << intersection(head, haed) << endl;
    display(head);
    display(haed);
}