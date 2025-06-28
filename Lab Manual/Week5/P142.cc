#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//after the first loop, we have to check if indeed there is a cycle
//this question does not quarantee the presence of a cycle, hence we need to 
//check  if a cycle exists
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
            return nullptr;
        ListNode *slow = head, *fast = head;
        while (fast!=nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }
        if (fast == nullptr || fast->next == nullptr)
            return nullptr;
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};