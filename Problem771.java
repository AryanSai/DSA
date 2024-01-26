// Jewels and Stones
// You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.
// Letters are case sensitive, so "a" is considered a different type of stone from "A".
// Example 1:
// Input: jewels = "aA", stones = "aAAbbbb"
// Output: 3
// Example 2:
// Input: jewels = "z", stones = "ZZ"
// Output: 0

import java.util.Hashtable;

class Problem771 {
    static int numJewelsInStones(String jewels, String stones) {
        Hashtable<Character, Integer> ht = new Hashtable<>();
        int count = 0;
        for (int i = 0; i < jewels.length(); i++) {
            ht.put(jewels.charAt(i), 1);
        }
        for (int i = 0; i < stones.length(); i++) {
            if (ht.containsKey(stones.charAt(i))) {
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        String jewels = "z";
        String stones = "z";
        System.out.println(numJewelsInStones(jewels, stones));
    }
}