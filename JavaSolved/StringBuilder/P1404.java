package Done.StringBuilder;
public class P1404 {
    public static int numSteps(String s) {
        int count = 0, n = 0;
        StringBuilder sb = new StringBuilder(s);
        while (sb.length() > 1) {
            n = sb.length() - 1;
            if (sb.charAt(n) == '0') {
                sb.deleteCharAt(n);
            } else {
                while (n >= 0 && sb.charAt(n) == '1') {
                    sb.setCharAt(n--, '0');
                }
                if (n < 0)
                    sb.insert(0, '1');
                else
                    sb.setCharAt(n, '1');
            }
            count++;
        }
        return count;
    }

    public static void main(String[] args) {
        String s = "1111011110000011100000110001011011110010111001010111110001";
        System.out.println(numSteps(s));
    }
}
