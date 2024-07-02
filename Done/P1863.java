package Done;


public class P1863 {
    public static void main(String[] args) {
        int[] nums = {1, 3};
        System.out.println(generateSubsets(nums));
    }

    public static int generateSubsets(int[] nums) {
        int n = nums.length;
        int numOfSubsets = 1 << n; 
        int sum = 0,xor;
        for (int i = 0; i < numOfSubsets; i++) {
            xor = 0; 
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) != 0) {
                    xor^=nums[j];
                }
            }
            sum+=xor;
        }
        return sum;
    }
}

