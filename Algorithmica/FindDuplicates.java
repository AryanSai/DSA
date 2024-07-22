import java.util.Arrays;

class FindDuplicates {

    // for each element starting from the first, check if its duplicate exists in
    // the remaining elements
    // TC: O(n^2)
    static int duplicates1(int[] in) {
        for (int i = 0; i < in.length; i++) {
            for (int j = i + 1; j < in.length; j++) {
                if (in[i] == in[j])
                    return in[i];
            }
        }
        return -1;
    }

    // sort+scan...way better than method 1
    // O(nlogn)
    static int duplicates2(int[] in) {
        Arrays.sort(in);
        for (int j = 0; j < in.length - 1; j++) {
            if (in[j] == in[j + 1])
                return in[j];
        }
        return -1;
    }

    // data structure pattern(uses lookup)
    // TC AND SC: O(N)
    static int duplicates3(int[] in) {
        boolean[] count = new boolean[in.length];
        for (int i : in) {
            if (count[i - 1])
                return i;
            count[i - 1] = true;
        }
        return -1;
    }

    // adhoc
    //instead of extra space, change the original array only with negatives
    // TC:O(N) SC:O(1)
    static int duplicates4(int[] in) {
        for (int i = 0; i < in.length; i++) {
            int temp = Math.abs(in[i]);
            if (in[temp] < 0)
                return temp;
            in[temp] *= -1;
        }
        return -1;
    }

    // [1,2,3,3]
    public static void testcase1(int[] in) {
        int i = 0;
        for (; i < in.length - 1; i++) {
            in[i] = i + 1;
        }
        in[i] = in.length - 1;
    }

    // [3,2,1,3]
    public static void testcase2(int[] in) {
        int i = 0;
        for (; i < in.length - 1; i++) {
            in[i] = in.length - 1 - i;
        }
        in[i] = in.length - 1;
    }

    public static void main(String[] args) {
        int n = 100000000;
        int[] in = new int[n];
        testcase2(in);
        // System.out.println(Arrays.toString(in));
        long start = System.currentTimeMillis();
        // System.out.println("Duplicate: "+ duplicates1(in));
        System.out.println("Duplicate: " + duplicates4(in));
        long end = System.currentTimeMillis();
        System.out.println("time: " + (end - start) / 1000.0);

    }
}