package Done;
class Problem344 {
    static void reverseString(char[] s) {
        int i = 0, j = s.length - 1;
        char temp;
        while (i <= j) {
            System.out.println(s[i]);
            System.out.println(s[j]);
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }

    public static void main(String[] args) {
        char[] s = { 'h' };
        reverseString(s);
        System.out.println(s);
    }
}