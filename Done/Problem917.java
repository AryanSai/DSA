package Done;
// 917. Reverse Only Letters(Easy)
// Given a string s, reverse the string according to the following rules:
// All the characters that are not English letters remain in the same position.
// All the English letters (lowercase or uppercase) should be reversed.
// Return s after reversing it.
// Example 1:
// Input: s = "ab-cd"
// Output: "dc-ba"
// Example 2:
// Input: s = "a-bC-dEf-ghIj"
// Output: "j-Ih-gfE-dCba"
// Example 3:
// Input: s = "Test1ng-Leet=code-Q!"
// Output: "Qedo1ct-eeLg=ntse-T!"
// 65to90 and 97to122

class Problem917 {
    static boolean isAlphabet(char c) {
        int i = (int) c;
        if (i >= 65 && i <= 90 || i >= 97 && i <= 122)
            return true;
        return false;
    }

    static String reverseOnlyLetters(String s) {
        int l = 0, u = s.length() - 1;
        char[] arr = s.toCharArray();
        while (l <= u) {
            if (isAlphabet(arr[l]) && isAlphabet(arr[u])) {
                char temp = arr[l];
                arr[l] = arr[u];
                arr[u] = temp;
                l++;
                u--;
            } else if (!isAlphabet(arr[l])) {
                l++;
            } else if (!isAlphabet(arr[u])) {
                u--;
            }
        }
        return new String(arr);
    }

    public static void main(String[] args) {
        System.out.println(reverseOnlyLetters("a-"));
    }
}
