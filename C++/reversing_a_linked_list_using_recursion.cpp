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

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool search(node *head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void deletion(node *&head, int val)
{
    node *temp = head;
    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    node *toDelete = temp->next;

    temp->next = temp->next->next;
    delete toDelete;
}

void deleteAtHead(node *&head)
{
    node *todelete = head;
    head = head->next;
    delete todelete;
}

node *reversal(node *&head)
{
    node *previous = NULL;
    node *current = head;
    node *nextptr;
    while (current != NULL)
    {
        nextptr = current->next;
        current->next = previous;
        previous = current;
        current = nextptr;
    }
    head = previous;
    return head;
}

node *reverseByRecursion(node *&head)
{
    if (head->next == NULL || head == NULL)
    {
        return head;
    }

    node *newHead = reverseByRecursion(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 7);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtHead(head, 5);
    cout << head << endl;
    // display(head);
    // cout << search(head, 4) << endl;
    //  deletion(head, 3);
    // display(head);
    // deleteAtHead(head);
    // display(head);
    head = reverseByRecursion(head);
    // insertAtTail(head, 9);
    // insertAtHead(head, 9);
    display(head);

    return 0;
}
