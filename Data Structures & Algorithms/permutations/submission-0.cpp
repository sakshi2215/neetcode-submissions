class Solution {
public:
    void solve(vector<vector<int>>&ans, vector<int>&temp, int count, vector<int>&nums, vector<bool>&chosen){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
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
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<bool>chosen(nums.size(), false);
        vector<int>temp;
        int count = 0;
        solve(ans, temp, count, nums, chosen);
        return ans;
    }
};
