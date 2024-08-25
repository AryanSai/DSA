#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int v)
    {
        val = v;
        next = nullptr;
    }
};

// O(1)
// pass by reference since we are changing the head also
void insertFront(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void insertEnd(Node *&head, int val)
{
    if (head == nullptr)
    {
        insertFront(head, val);
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    Node *newNode = new Node(val);
    temp->next = newNode;
}

void insert(Node *&head, int val, int pos)
{
    if (head == nullptr)
    {
        insertFront(head, val);
        return;
    }
    Node *temp = head;
    int count = 1;
    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    Node *newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
}

void print(Node *head)
{
    while (head != nullptr)
    {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void deleteFront(Node *&head)
{
    if (head == nullptr)
        return;
    Node *temp = head;
    head = head->next;
    free(temp);
}

void deleteEnd(Node *&head)
{
    if (head == nullptr)
        return;
    if (head->next == nullptr)
    {
        deleteFront(head);
        return;
    }
    Node *temp = head;
    while (temp->next->next != nullptr)
        temp = temp->next;
    Node *last = temp->next;
    temp->next = nullptr;
    free(last);
}

int main()
{
    // Node *head = nullptr;
    Node *head = new Node(2);
    Node *node = new Node(3);
    head->next = node;
    insertFront(head, 5);
    insertEnd(head, 10);
    insertFront(head, 1);
    print(head);
    insert(head, 11, 2);
    print(head);
    deleteFront(head);
    print(head);
    deleteEnd(head);
    print(head);
}