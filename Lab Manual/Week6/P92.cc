#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head)
            return head;
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        //go till the prev of the left node
        for (int i = 1; i < left; i++)
            prev = prev->next;
        ListNode *pre = nullptr, *curr = prev->next, *next = nullptr;
        //reverse the sublist
        for (int i = left; i <= right; i++) {
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        
        prev->next->next = curr;
        prev->next = pre; //simple
        return dummy->next;
    }
};