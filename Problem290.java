
// 290. Word Pattern (Easy)
// Given a pattern and a string s, find if s follows the same pattern.
// Here follow means a full match, such that there is a bijection between a letter in pattern
//  and a non-empty word in s.
// Example 1:
// Input: pattern = "abba", s = "dog cat cat dog"
// Output: true
// Example 2:
// Input: pattern = "abba", s = "dog cat cat fish"
// Output: false
// Example 3:
// Input: pattern = "aaaa", s = "dog cat cat dog"
// Output: false
import java.util.HashMap;

public class Problem290 {
    static boolean wordPattern(String pattern, String s) {
        HashMap<Character, String> ht = new HashMap<>();
        String[] tokens = s.split("[ ]");
        if (tokens.length != pattern.length()) {
            return false;
        }
        for (int i = 0; i < tokens.length;) {
            
        }
        return true;
    }

    public static void main(String[] args) {
        System.out.println(wordPattern("abba", "dog cat cat dog"));
    }
}
