import java.util.ArrayList;

class Problem136 {
    static int singleNumber(int[] nums) {
        ArrayList<Integer> arr = new ArrayList<Integer>(4);
        for (int num : nums) {
            if (arr.contains(num)) {
                System.out.println(num);
                int nu = num;
                arr.remove(Integer.valueOf(nu));
            } else {
                arr.add(num);
            }
        }
        if (arr.size() == 1) {
            return arr.get(0);
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] nums = { 1 ,2};
        int val = singleNumber(nums);

        System.out.println("Single Number is: " + val);
    }
}