class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        int count = 0;
        for(int j=0; j<nums.size();j++){
            if(nums[j]!=val){
                swap(nums[i], nums[j]);
                i++;
            }
            else{
                count++;
            }
        }
        return nums.size()-count;
    }
};