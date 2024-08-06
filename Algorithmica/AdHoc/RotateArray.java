package Algorithmica.AdHoc;

import java.util.Arrays;
import java.util.Random;

class RotateArray {

    // TC: O(kn) SC:O(1)
    // inefficient solution and long duration
    public static int[] rotateArray1(int[] arr, int k) {
        int n = arr.length, last;
        for (int i = 0; i < k; i++) {
            last = arr[n - 1];
            for (int j = n - 2; j >= 0; j--) {
                arr[j + 1] = arr[j];
            }
            arr[0] = last;
        }
        return arr;
    }

    // TC: O(n) SC:O(n)
    // but bad for memory; can cause OutOfMemory issue
    public static int[] rotateArray2(int[] arr, int k) {
        int n = arr.length;
        int[] sol = new int[n];
        for (int i = 0; i < n; i++) {
            sol[(i + k) % n] = arr[i];
        }
        return sol;
    }

    
    private static void reverse(int[] arr, int l, int u) {
        while (l < u) {
            int temp = arr[l];
            arr[l] = arr[u];
            arr[u] = temp;
            l++;
            u--;
        }
    }
    // TC: O(n) SC:O(1)
    public static void  rotateArray3(int[] arr, int k) {
        reverse(arr, 0, arr.length-1);
        reverse(arr, 0, k-1);
        reverse(arr, k, arr.length-1);
    }

    public static void main(String[] args) {
        int[] arr = { 3, 4, 5, 6, 1, 2 };
        System.out.println(Arrays.toString(arr));
        System.out.println(Arrays.toString(rotateArray2(arr, 2)));
        System.out.println(Arrays.toString(rotateArray1(arr, 2)));

        Random r = new Random();
        System.out.println(r.nextInt(10) + 1);

        long start = System.currentTimeMillis();
        System.out.println(start);

        int[] arr2 = { 3, 4, 5, 6, 1, 2 };
        rotateArray1(arr2,2);
        System.out.println(Arrays.toString(arr2));
    }
}