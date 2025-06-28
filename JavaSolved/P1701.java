package Done;
public class P1701 {
    public static double averageWaitingTime(int[][] customers) {
        int prev = customers[0][0], sum = 0, neww = 0;
        for (int i = 0; i < customers.length; i++) {
            if (customers[i][0] > prev)
                prev = customers[i][0];
            neww = prev + customers[i][1];
            sum += (neww - customers[i][0]);
            prev = neww;
        }
        return (double) sum / customers.length;
    }

    public static void main(String[] args) {
        int[][] arr = { { 1, 2 }, { 2, 5 }, { 4, 3 } };
        // System.out.println(arr[1][1]);
        System.out.println(averageWaitingTime(arr));
    }
}
