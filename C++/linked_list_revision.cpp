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
    display(head);
    // deleteAtHead(head);
    // display(head);
    head = reverseByRecursion(head);
    // insertAtTail(head, 9);
    // insertAtHead(head, 9);
    display(head);

    return 0;
}



// #include <iostream>
// using namespace std;

// class node
// {
// public:
//     int data;
//     node *next;
//     node *previous;

//     node(int val)
//     {
//         data = val;
//         next = NULL;
//         previous = NULL;
//     }
// };

// void insertAtTail(node *&head, int val)
// {
//     node *n = new node(val);
//     if (head == NULL)
//     {
//         head = n;
//         return;
//     }

//     node *temp = head;
//     while (temp->next != NULL)
//     {
//         temp = temp->next;
//     }

//     temp->next = n;
//     n->previous = temp;
// };

// void insertAtHead(node *&head, int val)
// {
//     node *n = new node(val);
//     n->next = head;
//     n->previous = head->previous;
//     if (head != NULL)
//     {
//         head->previous = n;
//     }

//     head = n;
// }

// void deleteAtHead(node *&head)
// {
//     node *temp = head;
//     temp->next->previous = NULL;
//     head = temp->next;
//     delete temp;
// }

// void deletion(node *&head, int val)
// {

//     if (head->data == val)
//     {

//         deleteAtHead(head);
//         return;
//     }

//     node *temp = head;
//     while (temp->data != val)
//     {
//         temp = temp->next;
//     }
//     temp->previous->next = temp->next;

//     if (temp->next != NULL)
//     {
//         temp->next->previous = temp->previous;
//     }

//     delete temp;
// }

// int length(node *head)
// {
//     int count = 0;
//     while (head != NULL)
//     {
//         head = head->next;
//         count++;
//     }
//     return count;
// }

// void makecircle(node *&head)
// {
//     node *temp = head;
//     while (temp->next != NULL)
//     {
//         temp = temp->next;
//     }
//     temp->next = head;
// }

// void insertincircle(node *&head, int val)
// {
//     node *n = new node(val);
//     if (head == NULL)
//     {
//         head = n;
//     }

//     node *temp = head;

//     while (temp->next != head)
//     {
//         temp = temp->next;
//     }
//     n->next = temp->next;
//     temp->next = n;
// }

// void deleteAtEnd(node *&head)
// {
//     node *temp = head;
//     node *dummy;
//     while (temp->next->next != head)
//     {
//         temp = temp->next;
//     }
//     dummy = temp->next;
//     temp->next = head;
//     delete dummy;
// }

// void evenAfterOdd(node* &head)
// {
//     node *odd = head;
//     node *even = head->next;
//     node *evenStart = even;
//     while (odd->next != NULL && even->next != NULL)
//     {
//         odd->next = even->next;
//         odd = odd->next;
//         even->next = odd->next;
//         even = even->next;
//     }
//     odd->next = evenStart;
//     if (even->next != NULL)
//     {
//         even->next == NULL;
//     }
// }

// void display(node *head)
// {
//     node *temp = head;
//     do
//     {
//         cout << temp->data << "->";
//         temp = temp->next;
//     } while (temp != NULL);

//     cout <<"NULL"<<endl;
// }

// int main()
// {
//     node *head = NULL;
//     node *haed = NULL;
//     insertAtTail(head, 1);
//     insertAtTail(head, 2);
//     insertAtTail(head, 3);
//     insertAtTail(head, 4);
//     insertAtTail(head, 5);
//     insertAtTail(head, 6);
//     insertAtTail(head, 7);
//     insertAtTail(head, 8);
//     insertAtTail(head, 9);
//     insertAtTail(head, 10);
//     insertAtTail(head, 11);
//     insertAtTail(head, 12);
//     evenAfterOdd(head);
//     display(head);
// }

