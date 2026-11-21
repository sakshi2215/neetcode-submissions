class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> nse(n, n);
        vector<int> pse(n, -1);

        stack<int> st;

        // Next Smaller Element
        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if(!st.empty()) {
                nse[i] = st.top();
            }

            st.push(i);
        }

        // Previous Smaller Element
        stack<int> pst;

        for(int i = 0; i < n; i++) {
            while(!pst.empty() && heights[pst.top()] >= heights[i]) {
                pst.pop();
            }

            if(!pst.empty()) {
                pse[i] = pst.top();
            }

            pst.push(i);
        }

        int area = 0;

        for(int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1;
            area = max(area, width * heights[i]);
        }

        return area;
    }
};