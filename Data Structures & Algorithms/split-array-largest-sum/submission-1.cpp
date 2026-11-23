class Solution {
public:
    bool isPossible(vector<int>&nums, int k, int mid){
        int days = 1;
        int weight = nums[0];

        for(int i=1; i<nums.size();i++){
            if(weight+ nums[i] > mid){
                weight = nums[i];
                days++;
            }
            else{
                weight+=nums[i];
            }
        }
        if(days <= k )return true;
        else return false;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = 0;
        int high = 0;

        for(int i=0;i<nums.size();i++){
            low = max(low, nums[i]);
            high+=nums[i];
        }

        int minSum=0;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(isPossible(nums, k, mid)){
                minSum = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return minSum;
    }
};