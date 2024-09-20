#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0, carry = 0;
        ListNode *curr = nullptr, *head = nullptr;
        while (l1 != nullptr || l2 != nullptr) {
            sum=0;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            if (sum >= 10) {
                sum = sum % 10;
                carry = 1;
            } else {
                carry = 0;
            }
            ListNode* neww = new ListNode(sum);
            if (curr == nullptr) {
                curr = neww;
                head = curr;
            } else {
                curr->next = neww;
                curr = curr->next;
            }
        }
        if (carry > 0)
            curr->next = new ListNode(1);
        return head;
    }
};