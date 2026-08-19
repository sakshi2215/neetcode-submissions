class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int i=0;
        int j=0;
        int prefixSum = 0;
        int minLength = INT_MAX;
        while(j < nums.size()){

            
            prefixSum+=nums[j];
            while(prefixSum >= target){
                minLength = min(minLength, j - i + 1);
                prefixSum-=nums[i];
                i++;
            }
            j++;
        }

        if(minLength == INT_MAX) return 0;

        return minLength;
    }
};