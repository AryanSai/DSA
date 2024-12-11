#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;
        while (temp) {
            count++;
            temp = temp->next;
        }
        ListNode dummy(0, head);
        ListNode* prevEnd = &dummy;
        while (count >= k) {
            ListNode *groupStart = prevEnd->next, *curr = groupStart,
                     *prev = nullptr, *next = nullptr;
            for (int i = 0; i < k; ++i) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            prevEnd->next = prev;
            groupStart->next = curr;
            prevEnd = groupStart;
            count -= k;
        }
        return dummy.next;
    }
};
