package Done;
// 1768. Merge Strings Alternately(Easy)
// You are given two strings word1 and word2. Merge the strings by adding letters in alternating 
// order, starting with word1. If a string is longer than the other, append the additional letters 
// onto the end of the merged string.
// Return the merged string.
// Example 1:
// Input: word1 = "abc", word2 = "pqr"
// Output: "apbqcr"
// Explanation: The merged string will be merged as so:
// word1:  a   b   c
// word2:    p   q   r
// merged: a p b q c r
// Example 2:
// Input: word1 = "ab", word2 = "pqrs"
// Output: "apbqrs"
// Explanation: Notice that as word2 is longer, "rs" is appended to the end.
// word1:  a   b 
// word2:    p   q   r   s
// merged: a p b q   r   s
// Example 3:
// Input: word1 = "abcd", word2 = "pq"
// Output: "apbqcd"
// Explanation: Notice that as word1 is longer, "cd" is appended to the end.
// word1:  a   b   c   d
// word2:    p   q 
// merged: a p b q c   d
class Problem1768 {
    static String mergeAlternately(String word1, String word2) {
        int maxx = Math.max(word1.length(), word2.length());
        StringBuilder sol = new StringBuilder();
        for (int i = 0; i < maxx; i++) {
            if (i < word1.length()) {
                if (!word1.substring(i, i + 1).isEmpty())
                    sol.append(word1.substring(i, i + 1));
            }
            if (i < word2.length()) {
                if (!word2.substring(i, i + 1).isEmpty())
                    sol.append(word2.substring(i, i + 1));
            }
        }
        return sol.toString();
    }
    public static void main(String[] args) {
        System.out.println(mergeAlternately("abcd", "pq"));
    }
}