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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        stack<ListNode*> st;
        ListNode* curr = head;
        int length = 0;
        while (curr) {
            st.push(curr);
            curr = curr->next;
            length++;
        }
        curr = head;
        ListNode* temp, *topNode;
        for (int i = 0; i < length / 2; i++) {
            temp = curr->next; 
            topNode = st.top();
            st.pop();
            curr->next = topNode; 
            topNode->next = temp; 
            curr = temp;
        }
        curr->next = nullptr;
    }
};