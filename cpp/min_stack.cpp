class MinStack {
public:
    void push(int x) {
        if (minStack.empty() || x<=minStack.top())
            minStack.push(x);
        numStack.push(x);
    }

    void pop() {
        if (!numStack.empty() && !minStack.empty())
        {
            if (numStack.top() == minStack.top())
                minStack.pop();
            numStack.pop();
        }
    }

    int top() {
        return numStack.top();
    }

    int getMin() {
        return minStack.top();
    }
private:
    stack<int> numStack;
    stack<int> minStack;
};