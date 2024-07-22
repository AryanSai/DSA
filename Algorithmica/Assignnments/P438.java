package Algorithmica.Assignnments;
import java.util.ArrayList;
import java.util.List;

class P438 {
    static boolean isAnagram(int[] count, String a, String b) {
        for (char c : a.toCharArray())
            count[c - 'a']++;
        for (char c : b.toCharArray())
            count[c - 'a']--;
        for (int i : count) {
            if (i != 0)
                return false;
        }
        return true;
    }

    static List<Integer> todo(String s, String p) {
        List<Integer> lt = new ArrayList<>();
        String sub;
        int len = p.length();
        int[] count = new int[26];
        for (int i = 0; i < s.length() - len + 1; i++) {
            sub = s.substring(i, i + len);
            // System.out.println(sub);
            if (isAnagram(count, sub, p))
                lt.add(i);
        }
        return lt;
    }

    public static void main(String[] args) {
        // String s = "sairam";
        // String st = s.substring(0, 3);
        // System.out.println(st);
        // System.out.println(isAnagram("abs", "ssa"));
        System.out.println(todo("abab", "ab"));
    }
}