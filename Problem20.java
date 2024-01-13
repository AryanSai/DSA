import java.util.HashMap;
import java.util.Stack;

public class Problem20 {

    static boolean isValid(String s) {
        HashMap<Character, Character> hm = new HashMap<>();
        hm.put('(', ')');
        hm.put('[', ']');
        hm.put('{', '}');

        Stack<Character> stack = new Stack<>();

        for (char bracket : s.toCharArray()) {
            if (hm.containsKey(bracket)) { // opening bracket
                stack.push(bracket);
            } else if (!stack.isEmpty() && hm.get(stack.peek()) == bracket) {// found closing, so pop
                stack.pop();
            } else {
                return false;
            }
        }

        return stack.isEmpty();
    }

    public static void main(String[] args) {
        String s = "(){}";
        boolean isValid = isValid(s);

        System.out.println("Is the string valid? " + isValid);
    }
}
