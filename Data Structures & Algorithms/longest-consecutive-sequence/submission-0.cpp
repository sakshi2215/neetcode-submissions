class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int>mpp;

        for(int i=0; i<nums.size(); i++){
            mpp[nums[i]]++;
        }
        int longest = 0;
        
        for(int i=0; i<nums.size(); i++){
            if(mpp.find(nums[i]-1)!=mpp.end()){
                continue;
            }
            else{
              int curr = nums[i];
              int length = 1;
              while(mpp.find(curr+1)!=mpp.end()){
                curr = curr + 1;
                length++;
              } 
              longest = max(longest, length); 
            }
        }
        return longest;
    }
};
