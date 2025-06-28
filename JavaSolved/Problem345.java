package Done;
// 345. Reverse Vowels of a String(Easy)
// Given a string s, reverse only all the vowels in the string and return it.
// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.
// Example 1:
// Input: s = "hello"
// Output: "holle"
// Example 2:
// Input: s = "leetcode"
// Output: "leotcede"
class Problem345 {
    static boolean isVowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            return true;
        return false;
    }

    static String reverseVowels(String s) {
        char[] arr = s.toCharArray();
        int l = 0, u = s.length() - 1;
        while (l <= u) {
            if (isVowel(arr[l]) && isVowel(arr[u])) {
                char temp = arr[l];
                arr[l] = arr[u];
                arr[u] = temp;
                l++;
                u--;
            } else if (!isVowel(arr[l])) {
                l++;
            } else if (!isVowel(arr[u])) {
                u--;
            }
        }
        String sol = new String(arr);
        return sol;
    }

    public static void main(String[] args) {
        System.out.println(reverseVowels("abe"));
    }
}