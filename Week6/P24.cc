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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) 
            return head;
        ListNode* first = head;
        ListNode* second = head->next;
        first->next = swapPairs(second->next); 
        second->next = first; 
        return second;
    }
};