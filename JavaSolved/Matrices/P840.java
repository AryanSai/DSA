package Done.Matrices;
class P840 {
    static boolean checkMagic(int[][] grid, int startRow, int startCol) {
        // row, column and diagonal sum
        int trueSum = 15; // sum==45 (from1 to 9). divide among 3 ==15. hence sum of a row or col must be
                          // 15!
        // check if all numbers are between 1 and 9 and are unique
        boolean[] exists = new boolean[10];
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                int val = grid[i][j];
                if (val < 1 || val > 9 || exists[val]) {
                    return false;
                }
                exists[val] = true;
            }
        }
        for (int i = 0; i < 3; i++) {
            int rowSum = grid[startRow + i][startCol] + grid[startRow + i][startCol + 1]
                    + grid[startRow + i][startCol + 2];
            int colSum = grid[startRow][startCol + i] + grid[startRow + 1][startCol + i]
                    + grid[startRow + 2][startCol + i];
            if (rowSum != trueSum || colSum != trueSum) {
                return false;
            }
        }
        int diagSum1 = grid[startRow][startCol] + grid[startRow + 1][startCol + 1] + grid[startRow + 2][startCol + 2];
        int diagSum2 = grid[startRow + 2][startCol] + grid[startRow + 1][startCol + 1] + grid[startRow][startCol + 2];

        if (diagSum1 != trueSum || diagSum2 != trueSum) {
            return false;
        }
        return true;
    }

    static int numMagicSquaresInside(int[][] grid) {
        int count = 0, rows = grid.length, cols = grid[0].length;
        for (int i = 0; i <= rows - 3; i++) {
            for (int j = 0; j <= cols - 3; j++) {
                if (checkMagic(grid, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }

    public static void main(String[] args) {
        // int[][] matrix = { { 4, 3, 8 }, { 9, 5, 1 }, { 2, 7, 6 } };
        // System.out.println(checkMagic(matrix, 0, 2, 0, 2));
        int[][] matrix = { { 4, 3, 8, 4 }, { 9, 5, 1, 9 }, { 2, 7, 6, 2 } };
        System.out.println(numMagicSquaresInside(matrix));
    }
}