class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int ans = 0;
        int i=0;
        int j= heights.size()-1;

        while( i< j){

            ans = max(ans, (j-i)* min(heights[i], heights[j]));

            if(heights[i] < heights[j]){
                i++;
            }
            else{
                j--;
            }

        }
        return ans;
    }
};
