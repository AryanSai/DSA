package Done.LinkedLists;
// 141. Linked List Cycle(Easy)
// Given head, the head of a linked list, determine if the linked list has a cycle in it.
// There is a cycle in a linked list if there is some node in the list that can be reached again by
// continuously following the next pointer. Internally, pos is used to denote the index of the node that
// tail's next pointer is connected to. Note that pos is not passed as a parameter.
// Return true if there is a cycle in the linked list. Otherwise, return false.

import java.util.HashMap;

class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
        next = null;
    }
}

class Problem141 {
    public static boolean hasCycle(ListNode head) {
        HashMap<ListNode, Integer> ht = new HashMap<>();
        ListNode curr = head;
        while (curr != null) {
            if (!ht.containsKey(curr)) {
                ht.put(curr, 1);
                curr = curr.next;
            } else {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        ListNode s = new ListNode(1);
        ListNode s1 = new ListNode(2);
        s.next = s1;
        ListNode s2 = new ListNode(3);
        s1.next = s2;
        ListNode s3 = new ListNode(3);
        s1.next = s3;
        System.out.println(hasCycle(s));
    }
}
