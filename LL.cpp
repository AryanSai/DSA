#include <iostream>
using namespace std;

struct Node
{
    int value;
    struct Node *next;
};

void displayList(struct Node *node)
{
    while (node != NULL)
    {
        cout << node->value << "->";
        node = node->next;
    }

    if (node == NULL)
    {
        cout << "NULL";
    }
}

void append(struct Node **head, int data)
{
    struct Node *newNode = new Node;
    newNode->value = data;
    newNode->next = NULL;

    struct Node *tail = *head;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = newNode;
    return;
}

int main()
{
    struct Node *head = NULL;

    append(&head, 12);
    displayList(head);
    return 0;
}