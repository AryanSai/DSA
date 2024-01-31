package ToDO.Problem1239;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Problem1239 {
    static int maxLength(List<String> arr) {
        String temp = "";
        Boolean bool = true;
        int[] dp = new int[arr.size()];
        int charBitmask = 0;
        for (String str : arr) {
            for (int i = 0; i < str.length(); i++) {
                char currentChar = str.charAt(i);
                int charIndex = currentChar - 'a'; // Assuming lowercase English letters
                if ((charBitmask & (1 << charIndex)) != 0) { // Check if the bit is already set
                    bool = false;
                    break;
                } else { // Set the bit to mark the character as appeared
                    charBitmask |= (1 << charIndex);
                }
            }
            if (bool == true) {
                temp += str;
                dp[arr.indexOf(str)] = temp.length();
                System.out.println("str=" + str + " " + "dp=" + dp[arr.indexOf(str)]+ " temp=" + temp);
            } else {
                System.out.println(str);
            }
        }
        System.out.println(dp[0]);
        Arrays.sort(dp);
        return dp[dp.length - 1];
    }

    public static void main(String[] args) {
        List<String> arr = new ArrayList<String>();
        // arr.add("abcdefghijklmnopqrstuvwxyz");
        // arr.add("un");
        // arr.add("iq");
        // arr.add("ue");
        arr.add("cha");
        arr.add("r");
        arr.add("act");
        arr.add("ers");
        System.out.println(maxLength(arr));
    }
}
