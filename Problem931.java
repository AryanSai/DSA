public class Problem931 {
    static int minFallingPathSum(int[][] matrix) {
        int[][] min = new int[matrix.length][matrix.length];
        for (int j = 0; j < matrix.length; j++) {
            min[0][j] = matrix[0][j];
        }

        for (int i = 1; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                if (j == 0) { // first column separately
                    min[i][j] = matrix[i][j] + Math.min(min[i - 1][j], min[i - 1][j + 1]);
                } else if (j == matrix[i].length - 1) { // last column separately
                    min[i][j] = matrix[i][j] + Math.min(min[i - 1][j - 1], min[i - 1][j]);
                } else { // rest of the columns
                    min[i][j] = matrix[i][j] + Math.min(min[i - 1][j - 1], Math.min(min[i - 1][j], min[i - 1][j + 1]));
                }
            }
        }

        // for (int i = 0; i < min.length; i++) {
        // for (int j = 0; j < min[i].length; j++) {
        // System.out.print(min[i][j] + "\t");
        // }
        // System.out.println();
        // }

        int lastRow = min.length - 1;
        int minElement = min[lastRow][0];
        for (int j = 1; j < min[lastRow].length; j++) {
            if (min[lastRow][j] < minElement) {
                minElement = min[lastRow][j];
            }
        }

        return minElement;
    }

    public static void main(String[] args) {

        int[][] matrix = {
                { -19, 57 },
                { -40, -5 } };

        System.out.println(minFallingPathSum(matrix));
    }
}
