package Done.Stack;
import java.util.LinkedList;
import java.util.Stack;

public class P1190 {
    static String reverseParentheses(String s) {
        Stack<Character> st = new Stack<>();
        LinkedList<Character> arr = new LinkedList<>();
        for (char c : s.toCharArray()) {
            if (c != ')') {
                st.push(c);
            } else {
                while (st.peek() != '(') {
                    arr.add(st.pop());
                }
                st.pop();
                while (!arr.isEmpty()) {
                    st.push(arr.removeFirst());
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        while (!st.isEmpty()) {
            sb.append(st.pop());
        }
        return sb.reverse().toString();
    }

    public static void main(String[] args) {
        String s = "(abcd)";
        System.out.println(reverseParentheses(s));
    }
}
