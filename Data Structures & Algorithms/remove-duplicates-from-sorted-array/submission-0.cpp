class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i =0;
        int k =0;

        while(i < nums.size()){
            if(nums[i]!=nums[k]){
                k++;
                swap(nums[i], nums[k]);    
            }
            i++;
        }
        return k+1;
    }
};