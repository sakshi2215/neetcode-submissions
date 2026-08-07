class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> input;
        for (int i = 0; i < position.size(); i++) {
            input.push_back({position[i], speed[i]});
        }
        sort(input.begin(), input.end(),
             [](pair<int, int> a, pair<int, int> b) { return a.first < b.first; });


        stack<pair<int, int>>st;
        int n = position.size();
        st.push(input[n-1]);
        

        for(int i=n-2; i>=0; i--){
            
                pair<int, int>top = st.top();
                st.pop();

                //check if they meet 
                int distance1 = (target - input[i].first);
                int distance2 = (target - top.first);

                double back = (double)distance1/input[i].second;
                double front = (double)distance2/top.second;

                if(back > front ){
                    st.push(top);
                    st.push(input[i]);
                }else{
                    st.push(top);
                }
                
        }
        
        return st.size();
    }
};
