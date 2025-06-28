package Done;
// 520. Detect Capital(Easy)
// We define the usage of capitals in a word to be right when one of the following cases holds:
// All letters in this word are capitals, like "USA".
// All letters in this word are not capitals, like "leetcode".
// Only the first letter in this word is capital, like "Google".
// Given a string word, return true if the usage of capitals in it is right.
// Example 1:
// Input: word = "USA"
// Output: true
// Example 2:
// Input: word = "FlaG"
// Output: false
class Problem520 {
    static boolean detectCapitalUse(String word) {
        int count = 0;
        boolean first = false;
        if (Character.isUpperCase(word.charAt(0))) {
            first = true;
        }
        for (int i = 0; i < word.length(); i++) {
            if (Character.isUpperCase(word.charAt(i))) {
                count++;
            }
        }
        System.out.println(count);
        if (count == word.length() || (first == true && count == 1) || count == 0) {
            return true;
        }
        return false;
    }

    public static void main(String[] args) {
        System.out.println(detectCapitalUse("fffF"));
    }
}