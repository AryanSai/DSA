package Done;
public class P1717 {
    static int score = 0;

    static String rreplace(String s, String sub, int sc) {
        StringBuilder sb = new StringBuilder(s);
        int i = 0;
        while (i <= sb.length() - 2) {
            if (sb.substring(i, i + 2).equals(sub)) {
                score += sc;
                sb.delete(i, i + 2);
                i = Math.max(0, i - 1); // move back to handle overlapping cases
            } else {
                i++;
            }
        }
        return sb.toString();
    }

    static int maximumGain(String s, int x, int y) {
        score = 0;
        if (x > y) {
            s = rreplace(s, "ab", x);
            s = rreplace(s, "ba", y);
        } else {
            s = rreplace(s, "ba", y);
            s = rreplace(s, "ab", x);
        }
        System.out.println(s);
        return score;
    }

    public static void main(String[] args) {
        System.out.println(maximumGain("aabbaaxybbaabb", 5, 4));
    }
}
