class Solution {
public:
    bool isPossible( int minSum , vector<int>&nums, int k){

        int currSum =0;
        int cK = 1;
       // int maxSum = INT_MIN;

        for(int i=0; i<nums.size(); i++){
            if(currSum+nums[i] > minSum  ){
                currSum = nums[i];
                cK++;
            }
            else{
                currSum+=nums[i];
               // maxSum = max(maxSum, currSum);
            }
        }
        return k >= cK;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = INT_MIN;
        int high = 0;

        for(int i=0; i<nums.size(); i++){
            low = max(low, nums[i]);
            high+=nums[i];
        }
        int ans = 0;

        while(low <= high){
            int mid = (low + high )/2;

            if(isPossible(mid, nums, k)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};