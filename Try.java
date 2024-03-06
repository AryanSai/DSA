
public class Try {
    public static void main(String[] args) {
        String s = "cabaabac";
        StringBuilder sb = new StringBuilder(s);
        // sb.deleteCharAt(0);
        int l = 0, u = sb.length() - 1;
        System.out.println(sb.charAt(l));
        System.out.println(sb.charAt(u));

        while (sb.charAt(l) == sb.charAt(u)) {
            sb.deleteCharAt(l);
            sb.deleteCharAt(u);
        }
        System.out.println(sb.toString());
        System.out.println(sb.length());

    }
}

// for (int num : sol) {
// System.out.println(num);
// }