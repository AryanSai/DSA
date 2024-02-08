package ToDO;
// 739. Daily Temperatures (Medium)

// Given an array of integers temperatures represents the daily temperatures, return an array answer such 
// that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If 
// there is no future day for which this is possible, keep answer[i] == 0 instead.
// Example 1:
// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]
// Example 2:
// Input: temperatures = [30,40,50,60]
// Output: [1,1,1,0]
// Example 3:
// Input: temperatures = [30,60,90]
// Output: [1,1,0]

// import java.util.Stack;

class Problem739 {
    static int[] dailyTemperatures(int[] temp) {
        int[] answer = new int[temp.length];
        // Stack<Integer> stack = new Stack<>();

        return answer;
    }

    public static void main(String[] args) {
        int[] temperatures = { 30, 60, 60, 90 };
        int[] answer = dailyTemperatures(temperatures);
        for (int i = 0; i < answer.length; i++) {
            System.out.print(answer[i] + " ");
        }
    }
}

// static int[] dailyTemperatures(int[] temp) {
// int[] answer = new int[temp.length];
// Stack<Integer> stack = new Stack<>();

// for (int i = 0; i < temp.length; i++) {
// while (!stack.isEmpty() && temp[i] > temp[stack.peek()]) {
// int prevIndex = stack.pop();
// answer[prevIndex] = i - prevIndex;
// }
// stack.push(i);
// }

// return answer;
// }

// top down
// public int[] dailyTemperatures(int[] temperatures) {
// int[] answer = new int[temperatures.length];
// for (int i = 0; i < temperatures.length; i++) {
// int count = 0;
// for (int j = i + 1; j < temperatures.length; j++) {
// if (temperatures[j] > temperatures[i]) {
// count++;
// answer[i] = count;
// break;
// } else {
// count++;
// }
// }
// }
// return answer;
// }

// bottom up
// static int[] dailyTemperatures(int[] temperatures) {
// int[] answer = new int[temperatures.length];
// int count = 0;
// for (int i = temperatures.length - 2; i >= 0; i--) {
// count = 0;
// for (int j = i + 1; j < temperatures.length; j++) {
// count++;
// if (temperatures[j] > temperatures[i]) {
// answer[i] = count;
// break;
// }
// }
// }
// return answer;
// }