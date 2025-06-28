#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//move the fast n steps
//then move both fast and slow equally
//when fast reaches the end, slow will point to the required node
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* fast = dummy, *slow=dummy;
        for(int i=0;i<=n;i++){
            fast=fast->next;
        }
        while(fast!=nullptr){
            fast=fast->next;
            slow=slow->next;
        }
        ListNode* del = slow->next;
        slow->next=slow->next->next;
        delete(del);
        
        return dummy->next;
    }
};