package Done;
import java.util.ArrayList;
import java.util.List;

class Problem2951 {
    static public List<Integer> findPeaks(int[] mountain) {
        List<Integer> sol = new ArrayList<>();
        for (int i = 1; i < mountain.length-1; i++) {
            System.out.println(i);
            if (mountain[i] > mountain[i + 1] && mountain[i] > mountain[i - 1]) {
                sol.add(i);
            }
        }
        return sol;
    }

    public static void main(String[] args) {
        int[] nums = { 4, 2, 1 };
        System.out.println(findPeaks(nums));
    }
}
