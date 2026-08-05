class StockSpanner {
   public:
    stack<pair<int, int> > st;
    int day;
    StockSpanner() {
        st.push({-1, 0});
        day = 0;
    }

    int next(int price) {
        day++;
        // remove the invalid item
        while (st.size() > 1 && st.top().first <= price) {
            st.pop();
        }
        int ans = 1;

        ans = day - st.top().second;

        st.push({price, day});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */