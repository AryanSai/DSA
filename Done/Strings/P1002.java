package Done.Strings;
// 1002. Find Common Characters(Easy)
// Given a string array words, return an array of all characters that show up in all 
// strings within thewords(including duplicates).You may return the answer in any order.
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
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;

class P1002 {
    static List<String> commonChars(String[] words) {
        HashMap<String,Integer> ht =  new HashMap<>();
        for(String word: words){
            HashMap<String,Integer> a =  new HashMap<>();
            for(int i=0;i<word.length();i++){
                a.put(word.substring(i,i+1),a.getOrDefault(word.substring(i,i+1),0)+1);
            }
            if(ht.isEmpty())
                ht.putAll(a);
            else{ 
                Iterator<Map.Entry<String, Integer>> iterator = ht.entrySet().iterator();
                while (iterator.hasNext()) {
                    Map.Entry<String, Integer> entry = iterator.next();
                    String key = entry.getKey();
                    Integer value = entry.getValue();
                    if (a.containsKey(key)) {
                        ht.put(key, Math.min(a.get(key), value));
                    } else {
                        iterator.remove(); 
                    }
                }
            }   
        }
        return new ArrayList<>(ht.keySet());
    }

    public static void main(String[] args) {
        String[] words = { "cool", "lock", "cook" };
        List<String> ls = commonChars(words);
        System.out.println(ls);
    }
}