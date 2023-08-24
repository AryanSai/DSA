// g++ LinkedList.cpp
// ./a.out

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void push(struct Node **head, int nodeData)
{
    struct Node *newNode1 = new Node;

    newNode1->data = nodeData;
    newNode1->next = (*head);

    (*head) = newNode1;
}

void insertAfter(struct Node *prevNode, int nodeData)
{
    if (prevNode == NULL)
    {
        cout << "the given previous node is required,cannot be NULL";
        return;
    }
    struct Node *newNode1 = new Node;
    newNode1->data = nodeData;
    newNode1->next = prevNode->next;
    prevNode->next = newNode1;
}

void append(struct Node **head, int nodeData)
{
    // creating the new node
    struct Node *newNode = new Node;
    newNode->data = nodeData;
    newNode->next = NULL;

    struct Node *last = *head;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    while (last->next != NULL) // traverse till the tail
        last = last->next;
    last->next = newNode;
    return;
}

void displayList(struct Node *node)
{
    while (node != NULL)
    {
        cout << node->data << "-->";
        node = node->next;
    }

    if (node == NULL)
        cout << "null";
}
int main()
{
    struct Node *head = NULL;
    append(&head, 15);
    push(&head, 25);
    push(&head, 35);
    append(&head, 45);
    insertAfter(head->next, 55);

    cout << "Final linked list: " << endl;
    displayList(head);

    return 0;
}