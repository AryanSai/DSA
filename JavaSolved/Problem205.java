package Done;

// Given two strings s and t, determine if they are isomorphic.
// Two strings s and t are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
// Example 1: Input: s = "egg", t = "add"
// Output: true
// Example 2: Input: s = "foo", t = "bar"
// Output: false
// Example 3:Input: s = "paper", t = "title"
// Output: true
import java.util.HashMap;

class Problem205 {
    static boolean isIsomorphic(String s, String t) {
        HashMap<Character, Character> ht = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char sc = s.charAt(i), tc = t.charAt(i);
            if (ht.containsKey(sc)) {
                if (ht.get(sc) == tc) {
                } else {
                    return false;
                }
            }else {
                if (ht.containsValue(tc)) {
                    return false;
                }
                ht.put(sc, tc);
            }
        }
        return true;
    }

    public static void main(String[] args) {
        String s = "a", t = "a";
        System.out.println(isIsomorphic(s, t));
    }
}