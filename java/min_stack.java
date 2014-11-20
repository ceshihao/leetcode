class MinStack {
    Stack<Integer> numStack = new Stack<Integer>();
    Stack<Integer> minStack = new Stack<Integer>();
    
    public void push(int x) {
        if (minStack.empty() || x<=minStack.peek())
            minStack.push(x);
        numStack.push(x);
    }

    public void pop() {
        if (!numStack.empty() && !minStack.empty())
        {
            if (numStack.peek().equals(minStack.peek()))
                minStack.pop();
            numStack.pop();
        }
    }

    public int top() {
            return numStack.peek();
    }

    public int getMin() {
            return minStack.peek();
    }
}