package Done;
// 1481. Least Number of Unique Integers after K Removals(Medium)
// Given an array of integers arr and an integer k. Find the least number of unique
// integers after removing exactly k elements.
// Example 1:
// Input: arr = [5,5,4], k = 1
// Output: 1
// Explanation: Remove the single 4, only 5 is left.
// Example 2:
// Input: arr = [4,3,1,1,3,3,2], k = 3
// Output: 2
// Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.

import java.util.HashMap;
import java.util.PriorityQueue;

class Problem1481 {
    static int findLeastNumOfUniqueInts(int[] arr, int k) {
        HashMap<Integer, Integer> hm = new HashMap<>();
        for (int num : arr) {
            hm.put(num, hm.getOrDefault(num, 0) + 1);
        }
        
        PriorityQueue<Integer> pq = new PriorityQueue<>(hm.values());
        while (k > 0) {
            int minFreq = pq.poll();
            if (minFreq <= k) {
                k -= minFreq;
            } else {
                pq.offer(minFreq);
                break;
            }
        }
        return pq.size();
    }

    public static void main(String[] args) {
        int[] nums = { 5,5,4};
        System.out.println(findLeastNumOfUniqueInts(nums, 1));
    }
}