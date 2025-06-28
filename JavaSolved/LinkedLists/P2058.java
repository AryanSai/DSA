package Done.LinkedLists;
// 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points (Medium)
// A critical point in a linked list is defined as either a local maxima or a local minima.
// A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.
// A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.
// Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.
// Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].

class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

class P2058 {
    static int[] nodesBetweenCriticalPoints(ListNode head) {
        ListNode prev = head;
        head = head.next;
        int count = 1, min_dist = Integer.MAX_VALUE, first = -1, old = 0;
        while (head.next != null) {
            if ((prev.val > head.val && head.next.val > head.val)
                    || (prev.val < head.val && head.next.val < head.val)) {
                if (first == -1)
                    first = count;
                else    
                    min_dist = Math.min(min_dist, count - old);
                old = count;
            }
            count++;
            prev = head;
            head = head.next;
        }
        System.gc();
        if (min_dist == Integer.MAX_VALUE) {
            return new int[] {-1, -1};
        }
        return new int[] { min_dist, old - first };
    }

    public static void main(String[] args) {
        System.out.println("sairam");
    }
}