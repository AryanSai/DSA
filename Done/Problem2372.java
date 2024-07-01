package Done;
// 2373. Largest Local Values in a Matrix(Easy)
// You are given an n x n integer matrix grid.
// Generate an integer matrix maxLocal of size (n - 2) x (n - 2) such that:
// maxLocal[i][j] is equal to the largest value of the 3 x 3 matrix in grid centered
//  around row i + 1 and column j + 1.
// In other words, we want to find the largest value in every contiguous 3 x 3 matrix
//  in grid.
// Return the generated matrix.
class Problem2372 {
    static int maxi(int[][] grid,int i, int j){
        int max = grid[i][j];
        for (int ii = i-1; ii <= i+1; ii++) {
            for (int jj = j-1; jj <= j+1; jj++){
                max = Math.max(max, grid[ii][jj]);
            }
        }
        return max;
    }

    static int[][] largestLocal(int[][] grid) {
        int[][] sol = new int[grid.length - 2][grid[0].length - 2];
        for (int i = 1; i < grid.length - 1; i++) {
            for (int j = 1; j < grid[i].length - 1; j++) {
                sol[i - 1][j - 1] = maxi(grid, i, j);
                // System.out.print(grid[i][j]);
            }
            // System.out.println();
        }
        return sol;
    }

    public static void main(String[] args) {
        int[][] grid = { {1,1,1,1,1},{1,1,1,1,1},{1,1,2,1,1},{1,1,1,1,1},{1,1,1,1,1}};
        int[][] sol = largestLocal(grid);
        for (int[] sol1 : sol) {
            for (int j = 0; j < sol1.length; j++) {
                System.out.print(sol1[j]);
            }
            System.out.println();
        }
    }
}