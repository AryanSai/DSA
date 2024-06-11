package Done;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class P1122 {
    static int[] relativeSortArray(int[] arr1, int[] arr2) {
        HashMap<Integer,Integer> ht = new HashMap<>();
        for(int i: arr1){
            ht.put(i, ht.getOrDefault(i, 0)+1);
        }
        int k =0;
        for (int j : arr2) {
            while(ht.get(j)!=0){
                arr1[k]=j;
                ht.put(j, ht.get(j)-1);
                k++;
            }
            if(ht.get(j)==0)
                ht.remove(j);
        }
        List<Integer> rem = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : ht.entrySet()) {
            Integer frequency = entry.getValue();
            for (int i = 0; i < frequency; i++) {
                rem.add(entry.getKey());
            }
        }
        Collections.sort(rem);
        for(Integer r: rem){
            arr1[k]=r;
            k++;
        }
        return arr1;
    }

    public static void main(String[] args) {
        int[] arr1 = {2,21,43,38,0,42,33,7,24,13,12,27,12,24,5,23,29,48,30,31};
        int[] arr2 = {2,42,38,0,43,21};
        int[] sol = relativeSortArray(arr1,arr2);
        System.out.println(Arrays.toString(sol));
    }
}
// [2,42,38,0,43,21,5,7,12,12,13,23,24,24,27,29,30,31,33,48]...