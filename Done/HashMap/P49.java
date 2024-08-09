package Done.HashMap;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

class P49 {
    static List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> l = new ArrayList<>();
        HashMap<String, List<String>> ht = new HashMap<>();
        for (String s : strs) {
            char[] charArray = s.toCharArray();
            Arrays.sort(charArray);
            String sortedString = new String(charArray);
            if (ht.containsKey(sortedString))
                ht.get(sortedString).add(s);
            else {
                ht.put(sortedString, new ArrayList<String>());
                ht.get(sortedString).add(s);
            }
        }
        for (List<String> group : ht.values()) {
            l.add(group);
        }
        return l;
    }

    public static void main(String[] args) {
        String[] strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
        System.out.println(groupAnagrams(strs));
    }
}