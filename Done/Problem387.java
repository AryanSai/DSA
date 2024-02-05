package Done;
// 387. First Unique Character in a String(Easy)
// Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
// Example 1:
// Input: s = "leetcode"
// Output: 0
// Example 2:
// Input: s = "loveleetcode"
// Output: 2
// Example 3:
// Input: s = "aabb"
// Output: -1

import java.util.HashMap;

class Problem387 {
    static int firstUniqChar(String s) {
        HashMap<Character, Integer> ht = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            ht.put(s.charAt(i), ht.getOrDefault(s.charAt(i), 0) + 1);
        }
        for (int i = 0; i < s.length(); i++) {
            if (ht.get(s.charAt(i)) == 1) {
                return i;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        System.out.println(firstUniqChar("leetcode"));
    }
}