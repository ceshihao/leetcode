import java.io.IOException;  
import java.util.Stack; 

public class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<Integer>();
        for (String token:tokens)
        {
            if (token.equals("+") || token.equals("-") || token.equals("*") || token.equals("/"))
            {
                int num2 = stack.pop();
                int num1 = stack.pop();
                if (token.equals("+")) num1 += num2;
                else if (token.equals("-")) num1 -= num2;
                else if (token.equals("*")) num1 *= num2;
                else if (token.equals("/")) num1 /= num2;
                stack.push(num1);
            }
            else
                stack.push(Integer.valueOf(token));
        }
        return stack.empty()?0:stack.pop();
    }
}