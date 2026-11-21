class StockSpanner {
private:
stack<pair<int, int>>s;
int days;

public:
    StockSpanner() {
        days = 0;
    }
    //previous greater element
    int next(int price) {
        days++;
        while(!s.empty() && s.top().first <= price){
            s.pop();
        }
        int ans = days;
        if(!s.empty()){
            ans = days - s.top().second;
        }
        s.push({price, days});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */