class Solution {
public:
    void solve(vector<int>& nums, int target, vector<vector<int>>& ans,
               vector<int>& temp, int index) {

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        if (target < 0 || index >= nums.size())
            return;

        // Pick
        temp.push_back(nums[index]);
        solve(nums, target - nums[index], ans, temp, index + 1);
        temp.pop_back();

        // Not pick (skip duplicates)
        int nextIndex = index + 1;
        while (nextIndex < nums.size() && nums[nextIndex] == nums[index]) {
            nextIndex++;
        }

        solve(nums, target, ans, temp, nextIndex);
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        sort(nums.begin(), nums.end());

        solve(nums, target, ans, temp, 0);

        return ans;
    }
};