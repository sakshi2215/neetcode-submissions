class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int i=0;
        int j=0;

        if(s1.size() > s2.size()) return false;
        unordered_map<char, int>mpp;

        for(int i=0; i<s1.size(); i++){
            mpp[s1[i]]++;
        }

        int count = s1.size();
        for(int j=0; j<s2.size(); j++){
            //check if invalid window
            if(mpp.find(s2[j])==mpp.end()){
                while(i<j){
                    mpp[s2[i]]++;
                    i++;
                }
                i = j+1;
                count = s1.size();
                continue;
            }
            //if character is useful
            if(mpp[s2[j]] > 0){
                mpp[s2[j]]--;
                count--;
            }
            else{
                while(s2[i]!=s2[j]){
                    mpp[s2[i]]++;
                    i++;
                    count++;
                }
                i++;
            }
            if(count == 0) return true;

        }
        return false;

    }
};
