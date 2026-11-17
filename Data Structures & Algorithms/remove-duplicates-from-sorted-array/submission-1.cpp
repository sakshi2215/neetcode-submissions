class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=1;
        int count = 0;
        while( j < nums.size()){
            if(nums[i]!=nums[j]){
                i++;
                nums[i] = nums[j];
            }
            else{
                count++;
            }
            j++;
        }
        return nums.size()-count;
    }
};