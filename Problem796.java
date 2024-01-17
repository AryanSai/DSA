class Problem796 {
    static boolean rotateString(String s, String goal) {
        StringBuilder sb = new StringBuilder(s);
        for (int i = 0; i <= sb.length() - 1; i++) {
            sb.append(sb.charAt(0));
            sb.deleteCharAt(0);
            if (sb.toString().equals(goal)) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        String s, goal;
        s = "abcde";
        goal = "cdeab";
        System.out.println(rotateString(s, goal));
    }
}