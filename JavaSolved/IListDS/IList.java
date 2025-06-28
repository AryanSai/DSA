package IListDS;

public interface IList {
    void addLast(int x);
    void addFirst(int x);
    void add(int i,int x);
    int get(int i);
    int removeFirst();
    int removeLast();
    int remove(int i);
    void display();
    int size();
    void sort();
    boolean contains(int x);
}
