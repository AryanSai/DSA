package Done;
class P861 {
    static int rowNum(int[] row) {
        int num = 0;
        for (int i = 0; i < row.length; i++) {
            num += Math.pow(2, i) * row[row.length - 1 - i];
        }
        return num;
    }

    static void flipCol(int[][] grid, int col) {
        for (int row = 0; row < grid.length; row++) {
            grid[row][col] = grid[row][col] ^ 1;
        }
    }

    static int matrixScore(int[][] grid) {
        int score = 0;

        // check for rows
        for (int i = 0; i < grid.length; i++) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < grid[0].length; j++) {
                    grid[i][j] = grid[i][j] ^ 1;
                }
            }
        }

        // check for columns
        for (int j = 0; j < grid[0].length; j++) {
            int count=0;
            for (int i = 0; i < grid.length; i++) {
                if (grid[i][j]==1) {
                    count++;
                }
            }
            if (2*count < grid.length) {
                flipCol(grid,j);
            }
        }

        // caclulate score
        for (int[] row : grid) {
            score+=rowNum(row);
        }

        for (int[] sol1 : grid) {
            for (int j = 0; j < sol1.length; j++) {
                System.out.print(sol1[j]);
            }
            System.out.println();
        }
        return score;
    }

    public static void main(String[] args) {
        int[][] grid = { { 0, 0, 1, 1 }, { 1, 0, 1, 0 }, { 1, 1, 0, 0 } };
        System.out.println(matrixScore(grid));
    }
}