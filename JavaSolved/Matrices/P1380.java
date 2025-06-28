package Done.Matrices;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class P1380 {
    static List<Integer> luckyNumbers(int[][] matrix) {
        int n = matrix.length, m = matrix[0].length;
        int[] minn = new int[n];
        int[] maxx = new int[m];
        Arrays.fill(minn, Integer.MAX_VALUE);
        Arrays.fill(maxx, Integer.MIN_VALUE);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                minn[i] = Math.min(minn[i], matrix[i][j]);
                maxx[j] = Math.max(maxx[j], matrix[i][j]);
            }
        }
        List<Integer> lt = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == minn[i] && matrix[i][j] == maxx[j])
                    lt.add(matrix[i][j]);
            }
        }
        return lt;
    }

    public static void main(String[] args) {
        int[][] arr = {
                { 3, 7, 8 }, { 9, 11, 13 }, { 15, 16, 17 } };

        System.out.println(luckyNumbers(arr));
    }
}