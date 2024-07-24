package Done.Sorting;
import java.util.Arrays;
import java.util.HashMap;
import java.util.OptionalInt;
import java.util.stream.IntStream;

class P2191 {
    static int[] sortJumbled(int[] mapping, int[] nums) {
        HashMap<Integer, Integer> ht = new HashMap<>();
        for (int num : nums) {
            int newNum = transformNumber(num, mapping);
            ht.put(num, newNum);
        }
        Integer[] numsInteger = Arrays.stream(nums).boxed().toArray(Integer[]::new);
        Arrays.sort(numsInteger, (a, b) -> {
            int comp = Integer.compare(ht.get(a), ht.get(b));
            if (comp == 0) {
                OptionalInt indexA = IntStream.range(0, nums.length)
                        .filter(i -> nums[i] == a)
                        .findFirst();
                OptionalInt indexB = IntStream.range(0, nums.length)
                        .filter(i -> nums[i] == b)
                        .findFirst();
                return Integer.compare(indexA.orElse(-1), indexB.orElse(-1));
            }
            return comp;
        });

        return Arrays.stream(numsInteger).mapToInt(Integer::intValue).toArray();
    }

    private static int transformNumber(int num, int[] mapping) {
        if (num == 0) return mapping[0];
        int newNum = 0, div = 1;
        while (num > 0) {
            newNum += mapping[num % 10] * div;
            num /= 10;
            div *= 10;
        }
        return newNum;
    }

    public static void main(String[] args) {
        int[] mapping = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
        int[] nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        System.out.println(Arrays.toString(sortJumbled(mapping, nums)));
    }
}
