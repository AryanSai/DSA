#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//using nth node from end solution
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* curr = head;
        int l = 1;
        while (curr->next != nullptr) { // find the LL length
            curr = curr->next;
            l++;
        }
        k = k % l;
        if (k == 0)
            return head;
        ListNode* slow = head; // one step behind head
        ListNode* fast = head;
        for (int i = 0; i < k; i++) {
            fast = fast->next;
        }
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        fast->next = head;
        head = slow->next;
        slow->next=nullptr;
        return head;
    }
};