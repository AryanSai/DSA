package ToDO;
// 1249. Minimum Remove to Make Valid Parentheses(Medium)
// Given a string s of '(' , ')' and lowercase English characters.
// Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.
// Formally, a parentheses string is valid if and only if:
// It is the empty string, contains only lowercase characters, or
// It can be written as AB (A concatenated with B), where A and B are valid strings, or
// It can be written as (A), where A is a valid string.
// Example 1:
// Input: s = "lee(t(c)o)de)"
// Output: "lee(t(c)o)de"
// Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
// Example 2:
// Input: s = "a)b(c)d"
// Output: "ab(c)d"
// Example 3:
// Input: s = "))(("
// Output: ""
// Explanation: An empty string is also valid.
// Constraints:
// 1 <= s.length <= 105
// s[i] is either'(' , ')', or lowercase English letter. 

import java.util.Stack;

class Problem1249 {
    static String minRemoveToMakeValid(String s) {
        StringBuilder sb = new StringBuilder();

        Stack<Character> st = new Stack<>();
        for (char c : s.toCharArray()) {
            if (c == '(') {
                st.push(c);
            } else if (c == ')') {
                if (!st.isEmpty() && st.peek() == '(')
                    st.pop();
                else
                    continue;
            }
            sb.append(c);
        }
        System.out.println(sb.toString());    
        if (st.isEmpty())
            return sb.toString();
        return "";
    }

    public static void main(String[] args) {
        System.out.println(minRemoveToMakeValid("(a(b(c)d)"));
    }
}
