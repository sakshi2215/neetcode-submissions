class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size()-1;

        int maxWater = INT_MIN;

        while(i<j){
            int currWater = min(heights[i], heights[j]) * (j-i);
            maxWater = max(maxWater, currWater);
            if(heights[i] < heights[j]) i++;
            else j--;
        }
        return maxWater;
        
    }
};
