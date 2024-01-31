package ToDO.Problem1239;

import java.util.ArrayList;
// import java.util.Arrays;
import java.util.List;

public class Problem1239copy {
    static int maxLength(List<String> arr) {
        String temp="";
        Boolean bool;
        int max = 0, charBitmask;
        while (!arr.isEmpty()) {
            charBitmask = 0;
            temp = "";
            bool = true;
            for (String str : arr) {
                bool = true;
                for (int i = 0; i < str.length(); i++) {
                    int charIndex = str.charAt(i) - 'a'; // Assuming lowercase English letters
                    if ((charBitmask & (1 << charIndex)) != 0) { // Check if the bit is already set
                        bool = false;
                        break;
                    } else { // Set the bit to mark the character as appeared
                        charBitmask |= (1 << charIndex);
                    }
                }
                if (bool) {
                    temp += str;
                    if (temp.length() >= max) {
                        max = temp.length();
                    }
                }
            }
            arr.remove(0);
        }
        System.out.println(temp);
        return max;
    }

    public static void main(String[] args) {
        List<String> arr = new ArrayList<String>();
        // "ab","ba","cd","dc","ef","fe","gh","hg","ij","ji","kl","lk","mn","nm","op","po"
        // arr.add("abcdefghijklmnopqrstuvwxyz");
        // arr.add("");
        // arr.add("cha");
        // arr.add("r");
        // arr.add("ac");
        // arr.add("ters");
        // arr.add("ab");
        // arr.add("ba");
        // arr.add("cd");
        // arr.add("dc");
        // arr.add("ef");
        // arr.add("fe");
        // arr.add("gh");
        // arr.add("hg");
        // arr.add("ij");
        // arr.add("ji");
        // arr.add("kl");
        // arr.add("lk");
        // arr.add("mn");
        // arr.add("nm");
        // arr.add("op");
        // arr.add("po");
        arr.add("a");
        arr.add("abc");
        arr.add("d");
        arr.add("de");
        arr.add("def");
        System.out.println(maxLength(arr));
    }
}


