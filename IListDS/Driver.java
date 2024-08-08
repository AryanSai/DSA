package IListDS;

public class Driver {

    public static void main(String[] args) {
        IList l = new ArrayList();
        for (int i = 0; i < 5; i++) {
            l.addLast(i+1);
            l.display();
        }
        for (int i = 6; i <= 20; i++) {
            l.addFirst(i);
            l.display();
        }
        
    }
}
