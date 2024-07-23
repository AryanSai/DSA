package Done.Sorting;
import java.util.Arrays;
import java.util.HashMap;

public class P1636 {
    static int[] frequencySort(int[] nums) {
        HashMap<Integer, Integer> ht = new HashMap<>();
        for (int i : nums) {
            ht.put(i, ht.getOrDefault(i, 0) + 1);
        }
        Integer[] arr = new Integer[nums.length];
        for (int i = 0; i < nums.length; i++) {
            arr[i] = nums[i];
        }
        Arrays.sort(arr, (a, b) -> {
            int comp = ht.get(a).compareTo(ht.get(b));
            if (comp == 0)
                return b.compareTo(a); // descending order
            return comp;
        });
        for (int i = 0; i < arr.length; i++) {
            nums[i] = arr[i];
        }
        return nums;
    }

    public static void main(String[] args) {
        int[] nums = { 1, 1, 2, 2, 2, 3 };
        System.out.println(Arrays.toString(frequencySort(nums)));
    }
}
