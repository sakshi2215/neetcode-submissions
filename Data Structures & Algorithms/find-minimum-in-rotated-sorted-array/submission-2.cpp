class Solution {
public:
    int findMin(vector<int> &nums) {
        int mini = INT_MAX;
        int low =0;
        int high = nums.size()-1;

        while(low<=high){
            int mid = low + (high-low)/2;

            //check if left part is sorted
            if(nums[mid] >= nums[low]){
                mini = min(mini, nums[low]);
                //them move to right side
                low = mid+1;
            }
            else{
                mini = min(mini, nums[mid]);
                high = mid;
            }
        }
        return mini;
    }
};
