class MinStack {
private:
int mini;
stack<pair<int, int>>s;
public:
    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int val) {
        mini = min(mini, val);
        s.push({val, mini});
    }
    
    void pop() {
        s.pop();
        if(s.empty()){
            mini = INT_MAX;
        }
        else{
            mini = s.top().second;
        }
        
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};
