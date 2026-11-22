class FreqStack {
private:
map<int, int>frequencyMap;
int maxFrequency;
map<int, stack<int>>mpp;
public:
    FreqStack() {
        maxFrequency = 0;
    }
    
    void push(int val) {

        frequencyMap[val]++;
        if(frequencyMap[val] > maxFrequency){
                maxFrequency = frequencyMap[val];
                mpp[maxFrequency] = stack<int>();
        }
        mpp[frequencyMap[val]].push(val);
    }
    
    int pop() {
        int num = mpp[maxFrequency].top();
        frequencyMap[num]--;
        mpp[maxFrequency].pop();
        if(mpp[maxFrequency].empty()){
            maxFrequency--;
        }
        return num;

        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */