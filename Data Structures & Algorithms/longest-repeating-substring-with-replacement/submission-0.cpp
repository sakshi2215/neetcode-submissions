class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        int maxFrequency = 0;
        int maxLength = 0;
        unordered_map<char, int>mpp;

        while(right < s.size()){
            //if the window is invalid
            mpp[s[right]]++;
            int windowSize = right - left + 1;
            maxFrequency = max(maxFrequency, mpp[s[right]]);
            while ((right - left + 1) - maxFrequency > k) {
                mpp[s[left]]--;
                left++;
            }
            maxLength = max(maxLength, right - left + 1);
            
            
            right++;
        }
        return maxLength;
    }
};
