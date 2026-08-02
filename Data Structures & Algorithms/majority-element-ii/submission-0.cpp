class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0;
        int count2 = 0;
        int nums1, nums2= INT_MAX;

        for(int i=0; i<nums.size(); i++){


            if(nums1 == nums[i]) count1++;
            else if(nums2 == nums[i]) count2++;
            else{
                if(count1==0){
                    nums1 = nums[i];
                    count1++;
                }
                else if(count2==0){
                    nums2 = nums[i];
                    count2++;
                } 
                else{
                    count1--;
                    count2--;
                }

            }
        }
        count1 = count2 = 0;
        for(int num: nums){
            if(num == nums1) count1++;
            else if(num == nums2) count2++;
        }

        vector<int>res;
        if(count1 > nums.size()/3) res.push_back(nums1);
        if(count2 > nums.size()/3) res.push_back(nums2);
        return res;

    }
};