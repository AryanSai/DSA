#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
// {
// }

int main()
{
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    node1->next = node2;
    node2->next = node3;

    // Accessing values in the linked list
    ListNode *l1 = node1;
    while (l1 != nullptr)
    {
        cout << l1->val << "->";
        l1 = l1->next;
    }
    cout << "\n";
    return 0;
}