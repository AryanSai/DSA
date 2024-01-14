class Problem125 {
    static boolean isPalindrome(String s) {
        String clean = s.replaceAll("[^a-zA-Z0-9]", "").toLowerCase();
        StringBuilder sai = new StringBuilder(clean);
        String rev = sai.reverse().toString();
        return clean.equals(rev);
    }

    public static void main(String[] args) {
        String str = "0P";
        boolean bool = isPalindrome(str);

        System.out.println(bool);
    }
}