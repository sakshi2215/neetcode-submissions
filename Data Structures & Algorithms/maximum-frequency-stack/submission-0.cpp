class FreqStack {
public:
    unordered_map<int, int>mpp;
    unordered_map< int , stack<int>> st;
    int maxFrequency;
    FreqStack() {
        maxFrequency = 0;
    }
    
    void push(int val) {

        mpp[val]++;
        if(mpp[val] > maxFrequency){
            maxFrequency= mpp[val];
            st[maxFrequency] = stack<int>();
        }
        st[mpp[val]].push(val);
        
    }
    
    int pop() {

        int answer = st[maxFrequency].top();
        st[maxFrequency].pop();
        mpp[answer]--;

        if(st[maxFrequency].empty()){
            maxFrequency--;
        }
        return answer;
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */