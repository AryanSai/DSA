package LinkedListDS;

public class Driver {
    public static void main(String[] args) throws Exception {
        LinkedList ll = new LinkedList();
        // ll.isEmpty();
        // ll.getSize();
        ll.addFirst(10);
        ll.addLast(130);
        ll.addAt(120,1);
        ll.addAt(123,2);
        ll.addLast(140);
        // ll.isEmpty();
        ll.print();
        // ll.getFirst();
        // ll.removeFirst();
        ll.remove(11);
        // ll.search(140);
        // ll.search(140);
        ll.print();
        // ll.getSize();
    }
}
