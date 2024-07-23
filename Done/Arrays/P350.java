package Done.Arrays;
// 350. Intersection of Two Arrays II (Easy)
// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the
// result must appear as many times as it shows in both arrays and you may return the result in any order.
// Example 1:
// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2,2]
// Example 2:
// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [4,9]
// Explanation: [9,4] is also accepted.
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class P350 {
    static int[] intersect(int[] nums1, int[] nums2) {
        ArrayList<Integer> l = new ArrayList<>();
        HashMap<Integer,Integer> ht1 =  new HashMap<>();
        HashMap<Integer,Integer> ht2 =  new HashMap<>();
        for(int i:nums1){
            ht1.put(i, ht1.getOrDefault(i, 0)+1);
        }
        for(int i:nums2){
            ht2.put(i, ht2.getOrDefault(i, 0)+1);
        }
        for(Map.Entry<Integer,Integer> e: ht1.entrySet()){
            int k = e.getKey(), v= e.getValue();
            if(ht2.containsKey(k)){
                int i=0,m=Math.min(v, ht2.get(k));
                while (i<m) {
                    l.add(k);
                    i++;
                }
            }
        }
        int[] arr = l.stream().mapToInt(i -> i).toArray();
        return arr;
    }

    public static void main(String[] args) {
        int[] nums1={1,2,2,1}, nums2={2};
        System.out.println(Arrays.toString(intersect(nums1,nums2)));
    }
}
