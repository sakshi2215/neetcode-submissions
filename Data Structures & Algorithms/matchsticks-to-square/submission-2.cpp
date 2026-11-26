
class Solution {
public:
     bool solve(vector<int>& nums, vector<int>& visited,
               int index, int currSum, int target,
               int k) {

        // All k-1 subsets formed.
        // Remaining elements must form the last subset.
        if(k == 1) return true;

        // Current subset completed.
        if(currSum == target) {
            return solve(nums, visited, 0, 0, target, k - 1);
        }

        for(int i = index; i < nums.size(); i++) {

            if(visited[i]) continue;

            if(currSum + nums[i] > target)
                continue;

            // Pick
            visited[i] = 1;

            if(solve(nums, visited, i + 1,
                     currSum + nums[i], target, k)) {
                return true;
            }

            // Backtrack
            visited[i] = 0;
        }

        return false;
    }
    bool makesquare(vector<int>& nums) {
        
        int k = 4;
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum % k != 0 || nums.size() < k)
            return false;

        int target = sum / k;

        sort(nums.rbegin(), nums.rend());

        if(nums[0] > target) return false;

        vector<int> visited(nums.size(), 0);

        return solve(nums, visited, 0, 0, target, k);
        

    }
};
