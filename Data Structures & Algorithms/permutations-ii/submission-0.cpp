class Solution {
public:
    void solve(set<vector<int>>&ans, vector<int>&temp, int count, vector<int>&nums, vector<bool>&chosen){
        if(temp.size()==nums.size()){
            ans.insert(temp);
            return;
        }
        if(count >= nums.size()) return;

        for(int i=0; i<nums.size(); i++){
            if(chosen[i]==true) continue;
            chosen[i] = true;
            temp.push_back(nums[i]);
            solve(ans, temp, count+1, nums, chosen);
            temp.pop_back();
            chosen[i] = false;
        }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>ans;
        vector<bool>chosen(nums.size(), false);
        vector<int>temp;
        int count = 0;
        solve(ans, temp, count, nums, chosen);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};