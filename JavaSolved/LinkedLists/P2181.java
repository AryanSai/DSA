package Done.LinkedLists;

public class P2181 {
    static ListNode todo(ListNode head) {
        ListNode prev=head;
        ListNode curr = head.next;
        int sum=0;
        while (curr!=null) {
            if(curr.val!=0)
                sum+=curr.val;
            else{
                prev.val=sum;
                sum=0;
                prev.next=curr.next;
                prev=curr.next;
            }
            curr=curr.next;    
        }
        System.gc();
        return head;
    }

    public static void main(String[] args) {
            ListNode s = new ListNode(1);
            ListNode s1 = new ListNode(2);
            s.next = s1;
            ListNode s2 = new ListNode(3);
            s1.next = s2;
            ListNode s3 = new ListNode(3);
            s1.next = s3;
            System.out.println(todo(s));
    }
}
