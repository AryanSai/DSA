package LinkedListDS;

public class LinkedList {
    // we dont want anyone outside this class to moodify these data members
    private Node head;

    LinkedList() {
        head = null;
    }

    public void print() {
        if (head == null)
            System.out.println("The linked list is empty! ");
        Node temp = head; // important..should not change the head
        while (temp != null) {
            System.out.print(temp.val + "->");
            temp = temp.next;
        }
        System.out.println();
    }

    public void isEmpty() {
        if (head == null)
            System.out.println("The linked list is empty! ");
        else
            System.out.println("The linked list is not empty! ");
    }

    public void addFirst(int val) {
        Node n = new Node(val);
        n.next = head;
        head = n;
    }

    public void addLast(int val) {
        Node n = new Node(val);
        if (head == null) {
            head = n;
            return;
        }
        Node temp = head;
        while (temp.next != null)
            temp = temp.next;
        temp.next = n;
    }

    public void addAt(int val, int pos) throws Exception {
        if (pos == 0)
            addFirst(val);
        else if (pos < 0)
            throw new Exception("Index out of bounds!");
        else {
            Node n = new Node(val), temp = head;
            for (int i = 1; i < pos && temp != null; i++) {
                temp = temp.next;
            }
            if (temp == null)
                throw new Exception("Index out of bounds!");
            n.next = temp.next;
            temp.next = n;
        }
    }

    public void getFirst() throws Exception {
        if (head == null)
            throw new Exception("Empty Linkedlist!!");
        System.out.println("First element is " + head.val);
    }

    public void getLast() throws Exception {
        if (head == null)
            throw new Exception("Empty Linkedlist!!");
        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }
        System.out.println("Last element is " + temp.val);
    }

    public void get(int pos) throws Exception {
        Node temp = head;
        for (int i = 0; i < pos && temp != null; i++) {
            temp = temp.next;
        }
        if (temp == null)
            throw new Exception("Index out of bounds!");
        System.out.println("Element at " + pos + " is " + temp.val);
    }

    public void getSize() {
        int size = 0;
        Node temp = head;
        while (temp != null) {
            size++;
            temp = temp.next;
        }
        System.out.println("The size of the linked list is: " + size);
    }

    public void removeFirst() throws Exception {
        if (head == null)
            throw new Exception("Empty Linkedlist!!");
        System.out.println("Removed the first element : " + head.val);
        head = head.next;
        System.gc();
    }

    public void removeLast() throws Exception {
        if (head == null)
            throw new Exception("Empty Linkedlist!!");
        Node temp = head, prev = null;
        while (temp.next != null) {
            prev = temp;
            temp = temp.next;
        }
        prev.next = null;
        System.out.println("Removed the last element: " + temp.val);
        System.gc();
    }

    public void remove(int pos) throws Exception {
        if (head == null)
            throw new Exception("Empty Linkedlist!!");
        if (pos == 0)
            removeFirst();
        else {
            Node temp = head;
            for (int i = 1; i < pos && temp != null; i++) {
                temp = temp.next;
            }
            if (temp == null)
                throw new Exception("Index out of bounds!");
            System.out.println("Removed the element: " + temp.next.val);
            temp.next = temp.next.next;
            System.gc();
        }
    }

    public void search(int valu) throws Exception {
        if (head == null)
            throw new Exception("Empty Linkedlist!!");
        Node temp = head;
        int i = 0;
        while (temp != null) {
            if (temp.val == valu){
                System.out.println("The value " + valu + " exists at " + i);
                return;
            }else {
                temp = temp.next;
                i++;
            }
        }
        System.out.println("The value " + valu + " does not exist!");
    }
}
