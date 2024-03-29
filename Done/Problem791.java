package Done;
// 791. Custom Sort String(Medium)
// You are given two strings order and s. All the characters of order are unique and were sorted in some
// custom order previously.
// Permute the characters of s so that they match the order that order was sorted. More specifically,
//if a character x occurs before a character y in order, then x should occur before y in the permuted string.
// Return any permutation of s that satisfies this property.
// Example 1:
// Input:  order = "cba", s = "abcd" 
// Output:  "cbad" 
// Explanation: "a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a".
// Since "d" does not appear in order, it can be at any position in the returned string."dcba", "cdba", "cbda"
//  are also valid outputs.
// Example 2:
// Input:  order = "bcafg", s = "abcd" 
// Output:  "bcad" 
// Explanation: The characters "b", "c", and "a" from order dictate the order for the characters in s.
//  The character "d" in s does not appear in order, so its position is flexible.
// Following the order of appearance in order, "b", "c", and "a" from s should be arranged as
//  "b", "c", "a". "d" can be placed at any position since it's not in order. The output "bcad" 
// correctly follows this rule. Other arrangements like "bacd" or "bcda" would also be valid, as long as 
// "b", "c", "a" maintain their order.
// Constraints:
// 1 <= order.length <= 26
// 1 <= s.length <= 200
// order and s consist of lowercase English letters.
// All the characters of order are unique.

import java.util.HashMap;

class Problem791 {
    static String customSortString(String order, String s) {
        HashMap<Character, Integer> ht = new HashMap<>();
        StringBuilder sb = new StringBuilder();
        for (char c : s.toCharArray()) {
            ht.put(c, ht.getOrDefault(c, 0) + 1);
        }
        for (char c : order.toCharArray()) {
            if (ht.containsKey(c)) {
                int count = ht.get(c);
                for (int i = 0; i < count; i++) {
                    sb.append(c);
                }
                s = s.replaceAll(String.valueOf(c), "");
            }
        }
        return sb.toString() + s;
    }

    public static void main(String[] args) {
        System.out.println(customSortString("bcafg", "abcd"));
    }
}

// char[] oArr = order.toCharArray();
// StringBuilder sb = new StringBuilder();
// for (char c : oArr) {
// if (s.indexOf(c) > 0) {
// sb.append(c);
// s = s.replaceFirst(String.valueOf(c), "");
// }
// }
// return sb.toString() + s;