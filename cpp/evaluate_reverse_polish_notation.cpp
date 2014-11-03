class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> num_stack;
        for (int i=0; i<tokens.size(); ++i)
        {
            if (tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/")
            {
                int num1 = num_stack.top();
                num_stack.pop();
                int num2 = num_stack.top();
                num_stack.pop();
                if (tokens[i]=="+") num2 += num1;
                else if (tokens[i]=="-") num2 -= num1;
                else if (tokens[i]=="*") num2 *= num1;
                else if (tokens[i]=="/") num2 /= num1;
                num_stack.push(num2);
            }
            else
                num_stack.push(stoi(tokens[i]));
        }
        int result = num_stack.top();
        return result;
    }
};