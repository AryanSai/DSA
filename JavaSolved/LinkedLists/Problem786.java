package Done.LinkedLists;
// 876. Middle of the Linked List(Easy)
// Given the head of a singly linked list, return the middle node of the linked list.
// If there are two middle nodes, return the second middle node.
// Example 1:
// Input: head = [1,2,3,4,5]
// Output: [3,4,5]
// Explanation: The middle node of the list is node 3.
// Example 2:
// Input: head = [1,2,3,4,5,6]
// Output: [4,5,6]
// Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.

import java.util.HashMap;

public class Problem786 {
    static ListNode middleNode(ListNode head) {
        HashMap<Integer, ListNode> ht = new HashMap<>();
        int count = 0;
        while (head != null) {
            ht.put(count, head);
            count++;
            head = head.next;
        }
        return ht.get(count / 2);
    }

    public static void main(String[] args) {
        ListNode s = new ListNode(1);
        ListNode s1 = new ListNode(2, s);
        ListNode s2 = new ListNode(3, s1);
        ListNode s3 = new ListNode(4, s2);
        ListNode sol = middleNode(s3);
        System.out.println(sol.val);
    }
}