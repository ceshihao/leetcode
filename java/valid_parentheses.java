public class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<Character>();
        for (int i=0; i<s.length(); ++i)
        {
            char c = s.charAt(i); 
            if (c == '(' || c =='[' || c == '{')
                stack.push(c);
            else if (c == ')' || c ==']' || c == '}')
            {
                if (stack.empty()) return false;
                char prev = stack.pop();
                if (!(c == ')' && prev == '(' || c == ']' && prev == '[' || c == '}' && prev == '{'))
                    return false;
            }
            else
                return false;
        }
        return stack.empty();
    }
}