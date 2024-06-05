package Done;
public class P1404 {
    static int numSteps(String s) {
        int num = Integer.parseInt(s, 2), count = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) == '1') {
                num = num + 1;
            }
            num = num >> 1;
            count++;
        }
        return count;
    }
    public static void main(String[] args) {
        // System.out.println("0101".charAt(0)-'0');
        System.out.println(numSteps("1101"));
    }
}
