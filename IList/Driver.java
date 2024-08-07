package IList;

public class Driver {

    public static void main(String[] args) {
        IList l = new ArrayList();
        for (int i = 0; i < 5; i++) {
            l.addLast(i+1);
            l.display();
        }
        
    }
}
