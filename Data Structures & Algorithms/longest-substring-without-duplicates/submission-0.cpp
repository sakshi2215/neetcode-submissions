class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = 0;

        int i =0;
        int j = 0;
        unordered_map<char, int>mpp;

        while( j < s.size()){
            //check for invalid window
            while(mpp.find(s[j])!=mpp.end()){
                mpp.erase(s[i]);
                i++;
            }
            length = max( j - i +1, length);
            mpp[s[j]]++;
            j++;
        }
        return length;
    }
};
