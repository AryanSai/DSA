package Done.SubArrays;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class P1508 {
    static int rangeSum(int[] nums, int n, int left, int right) {
        List<Integer> l = new ArrayList<>();
        for (int k = 0; k < nums.length; k++) { // k -> starting point
            for (int i = k; i < nums.length; i++) { // i -> ending point
                int count = 0;
                for (int j = k; j <= i; j++) {
                    System.out.print(nums[j] + " ");
                    count += nums[j];
                }
                l.add(count);
                System.out.println("count=" + count);
            }
        }
        System.out.println(l);
        Collections.sort(l);
        System.out.println(l);
        int sum = 0;
        for (int i = left; i <= right; i++) {
            sum += l.get(i);
        }
        return sum;
    }

    public static void main(String[] args) {
        int[] nums = { 1, 2, 3, 4 };

    }
}