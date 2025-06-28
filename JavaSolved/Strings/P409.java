package Done.Strings;
import java.util.*;

class P409 {
    public static void main(String[] args) {
        String s = "abccccdd";
        HashMap<Character, Integer> ht = new HashMap<>();
        for (char c : s.toCharArray()) {
            ht.put(c, ht.getOrDefault(c, 0) + 1);
        }
        int count = 0, first = 0;
        for (Map.Entry<Character, Integer> e : ht.entrySet()) {
            if (e.getValue() % 2 == 0) {
                count += e.getValue();
            } else {
                count += e.getValue();
                if (first == 0)
                    first = 1;
                else
                    count -= 1;
            }
        }
        System.out.println(count);
    }
}