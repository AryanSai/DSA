#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr)
            return nullptr;
        
        head->next = removeElements(head->next,val);

        if(head->val==val){
            ListNode* node = head->next;
            delete(head);
            return node;
        }
        return head;
    }
};