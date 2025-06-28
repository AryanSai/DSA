package Done;

import java.util.Arrays;

class P2037 {
    static int minMovesToSeat(int[] seats, int[] students) {
        Arrays.sort(seats);
        Arrays.sort(students);
        int sum =0;
        for(int i=0;i<seats.length;i++){
            sum+=(Math.abs(students[i]-seats[i]));
        }
        return sum;
    }

    public static void main(String[] args) {
        int[] seats = { 3, 1, 5 };
        int[] students = { 2, 7, 4 };
        System.out.println(minMovesToSeat(seats, students));
    }
}