class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int>mpp;
        set<vector<int>>temp;
        vector<vector<int>>ans;

        for(int i=0; i<nums.size()-1; i++){
            for(int j=i+1; j<nums.size(); j++){
                int num =  - nums[i] - nums[j];
                if(mpp.find(num)!=mpp.end()){
                    vector<int>tempVector;
                    tempVector.push_back(num);
                    tempVector.push_back(nums[i]);
                    tempVector.push_back(nums[j]);
                    sort(tempVector.begin(), tempVector.end());
                    temp.insert(tempVector);
                }
            }
            mpp[nums[i]] = i;
        }

        for(auto it: temp){
            ans.push_back(it);
        }
        return ans;
    }
};
