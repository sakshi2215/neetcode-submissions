class Solution {
public:
    void solve(vector<int>&nums, int target, vector<vector<int>>&ans, vector<int>&temp, int index){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(target < 0 || index >= nums.size()) return;

        temp.push_back(nums[index]);
        solve(nums, target-nums[index], ans, temp, index);
        temp.pop_back();

        solve(nums, target, ans, temp, index+1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        int index=0;
        solve(nums, target, ans, temp, index);
        return ans;
    }
};
