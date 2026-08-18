class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int>mpp;

        int i=0;
        int j= 0;

        while(j < nums.size()){
            //check if valid window
            if(j - i >  k){
                mpp.erase(nums[i]);
                i++;
            }
            if(mpp.find(nums[j])!=mpp.end()) return true;
            mpp[nums[j]] = 1;
            j++;
        }
        return false;
    }
};