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
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        stack<int> st;
        while (fast != nullptr && fast->next != nullptr) {
            st.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast != nullptr) {
            slow = slow->next;
        }
        while (slow != nullptr) {
            if (slow->val != st.top()){
                return false;
            }
            st.pop();
            slow = slow->next;
        }
        return true;
    }
};