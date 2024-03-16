package ToDO;
// 1002. Find Common Characters(Easy)

// Given a string array words, return an array of all characters that show up in all strings within the
// words (including duplicates). You may return the answer in any order.
// Example 1:
// Input: words = ["bella","label","roller"]
// Output: ["e","l","l"]
// Example 2:
// Input: words = ["cool","lock","cook"]
// Output: ["c","o"]
// Constraints:
// 1 <= words.length <= 100
// 1 <= words[i].length <= 100
// words[i] consists of lowercase English letters.

import java.util.ArrayList;
import java.util.List;

class Problem1002 {
    static List<String> commonChars(String[] words) {
        List<String> ls = new ArrayList<>();
        for (int i = 0; i < words[0].length(); i++) {
            for (String word : words) {
                if (word.contains(words[0].substring(i, 1))) {
                    word.replace(words[0].substring(i, 1), "");
                }
            }
        }
        return ls;
    }

    public static void main(String[] args) {
        String[] words = { "cool", "lock", "cook" };
        List<String> ls = commonChars(words);
        for (String l : ls) {
            System.out.println(l);
        }
    }
}