class Solution {
public:
    void solve(vector<int>&nums, int index, int &xors, int & sum){
        if(index >= nums.size()){
            sum+=xors;
            return;
        }
        //pick
        xors = xors ^ nums[index];
        solve(nums, index+1, xors, sum);
        xors = xors ^ nums[index];

        solve(nums, index+1, xors, sum);
    }
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        int xors = 0;
        solve(nums, 0, xors, sum);
        return sum;
    }
};