#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp=head,*dum;
        while(temp!=nullptr && temp->next!=nullptr){
            if(temp->val==temp->next->val){
                dum=temp->next;
                temp->next=temp->next->next;
                delete dum;
            }else{
                temp=temp->next;
            }
        }
        return head;
    }
};