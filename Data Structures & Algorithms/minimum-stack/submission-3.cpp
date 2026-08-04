class MinStack {
   public:
    stack<pair<int, int>> s;
    int mini;
    MinStack() { mini = INT_MAX; }

    void push(int val) {
        mini = min(mini, val);
        s.push({val, mini});
    }

    void pop() {
        s.pop();
        if (s.empty())
            mini = INT_MAX;
        else
            mini = s.top().second;
    }

    int top() { return s.top().first; }

    int getMin() { return s.top().second; }
};
