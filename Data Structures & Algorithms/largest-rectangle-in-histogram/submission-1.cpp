class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>nse(n , n);
        vector<int>pse(n, -1);

        stack<int>st;

        for(int i=0; i<heights.size(); i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()){
                pse[i] = st.top();
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i= n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()){
                nse[i] = st.top();
            }
            st.push(i);
        }

        

        int ans = 0;
        for(int i=0; i<n;i++){
            int temp = (nse[i] - pse[i] -1)*heights[i];
            if(temp > ans){
                ans = temp;
            }
        }
        return ans;
    }
};
