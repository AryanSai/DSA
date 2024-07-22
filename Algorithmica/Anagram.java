package Algorithmica;

import java.util.Arrays;
import java.util.Random;

public class Anagram {
    // sort and check TC: O(nlogn) SC:O(n)
    static boolean anagram1(String s, String t) {
        char[] ss = s.toCharArray();
        char[] tt = t.toCharArray();
        Arrays.sort(ss);
        Arrays.sort(tt);
        for (int i = 0; i < s.length(); i++) {
            if (ss[i] != tt[i])
                return false;
        }
        return true;
    }

    // TC: O(n) SC:O(k)
    static boolean anagram2(String s, String t) {
        int[] count = new int[26];
        for (char c : s.toCharArray()) {
            count[c - 'a']++;
        }
        for (char c : t.toCharArray()) {
            count[c - 'a']--;
        }
        for (int i = 0; i < s.length(); i++) {
            if (count[i] != 0)
                return false;
        }
        System.out.println(Arrays.toString(count));
        return true;
    }

    private static String randomString(int n) {
        String res = "";
        Random r = new Random();
        for (int i = 0; i < n; i++) {
            char t = (char) ('a' + r.nextInt(n));
            res += t;
        }
        return res;
    }

    public static void main(String[] args) {
        String s = randomString(10);
        String t = randomString(10);
        System.out.println(s+" "+t);
        System.out.println(anagram1(s, t));
        System.out.println(anagram2(s, t));
    }
}
