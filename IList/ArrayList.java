package IList;

public class ArrayList implements IList {

    private int[] array;
    private int size;

    //constructor
    public ArrayList() {
        array = new int[10];
        size = 0;
    }

    private boolean isFull() {
        return size == array.length;
    }

    private void resize() {
        int[] newArray = new int[2 * array.length];
        //copy the elements to the new array
        System.arraycopy(array, 0, newArray, 0, array.length);
        array = newArray;
    }

    private void shiftRight(int p) {
        for (int i = size - 1; i >= p; i--) {
            array[i + 1] = array[i];
        }
    }

    private void shiftLeft(int p) {
        for (int i = p; i < size; i++) {
            array[i] = array[i + 1];
        }
    }

    @Override
    public void addLast(int x) {
        if (isFull()) {
            resize();
        }
        array[size++] = x;
    }

    @Override
    public void addFirst(int x) {
        if (isFull()) {
            resize();
        }
        shiftRight(0);
        array[0] = x;
        ++size;
    }

    @Override
    public void add(int i, int x) {
        if (i < 0 || i >= size) {
            return;
        }
        if (isFull()) {
            resize();
        }
        shiftRight(i);
        array[i] = x;
        ++size;
    }

    @Override
    public int get(int i) {
        if (size == 0 || i < 0 || i >= size) {
            return Integer.MIN_VALUE;
        }
        return array[i];
    }

    @Override
    public int removeFirst() {
        if (size == 0) {
            return Integer.MIN_VALUE;
        }
        int result = array[0];
        size--;
        shiftLeft(0);
        return result;
    }

    @Override
    public int removeLast() {
        if (size == 0) {
            return Integer.MIN_VALUE;
        }
        return array[--size];
    }

    @Override
    public int remove(int i) {
        if (size == 0 || i < 0 || i >= size) {
            return Integer.MIN_VALUE;
        }
        int result = array[i];
        size--;
        shiftLeft(i);
        return result;
    }

    @Override
    public void display() {
        for (int i = 0; i < size; i++) {
            System.out.print(array[i] + " ");
        }
        System.out.println();
    }

    @Override
    public int size() {
        return size;
    }

    @Override
    public void sort() {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'sort'");
    }

    @Override
    public boolean contains(int x) {
        for (int i = 0; i < size; i++) {
            if (array[i] == x) {
                return true;
            }
        }
        return false;
    }
}
