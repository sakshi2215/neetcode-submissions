class Solution {
public:
    void solve(vector<int>&nums, set<vector<int>>&ans, vector<int>&temp, int index){
        if(index >= nums.size()){
            ans.insert(temp);
            return;
        }
        temp.push_back(nums[index]);
        solve(nums, ans, temp, index+1);
        temp.pop_back();
        while(index +1  < nums.size() && nums[index]==nums[index+1]){
            index++;
        }
        solve(nums, ans, temp, index+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>ans;
        vector<int>temp;
        int index = 0;
        sort(nums.begin(), nums.end());
        solve(nums, ans, temp, index);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
