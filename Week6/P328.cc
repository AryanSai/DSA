#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *odd=head, *even=head->next, *dummy=even;
        while (even && even->next) {
            odd->next=even->next;
            odd=odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = dummy;
        return head;
    }
};