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

node *reverseknodes(node *&head, int k)
{
    node *prev = NULL;
    node *current = head;
    node *next;
    int count = 0;

    while (current != NULL && count < k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    if (next != NULL)
    {
        head->next = reverseknodes(next, k);
    }

    return prev;
}

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
    insertAtTail(head, 7);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    // insertAtHead(head, 5);
    // cout << head << endl;
    //  display(head);
    //  cout << search(head, 4) << endl;
    //   deletion(head, 3);
    // display(head);
    //  deleteAtHead(head);
    //  display(head);
    // head = reverseByRecursion(head);
    //  insertAtTail(head, 9);
    //  insertAtHead(head, 9);
    head = reverseknodes(head, 2);
    display(head);

    return 0;
}