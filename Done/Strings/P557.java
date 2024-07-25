package Done.Strings;
class P557 {
    static String reverseWords(String s) {
        StringBuilder sol = new StringBuilder();
        String[] words = s.split(" ");
        for (String word : words) {
            sol.append(new StringBuilder(word).reverse()).append(" ");
        }
        return sol.toString().trim();
    }

    public static void main(String[] args) {

        System.out.println(reverseWords("Let's take LeetCode contest"));
    }
}