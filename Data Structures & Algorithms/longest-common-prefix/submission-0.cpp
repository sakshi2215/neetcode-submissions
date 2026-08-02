class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        
        for(int i=0; i<strs[0].size(); i++){

            bool same = true;
            //only check if that index exist
            for(int j = 1; j<strs.size(); j++){
                if(i >= strs[j].size() || strs[0][i]!=strs[j][i]){
                    same = false;
                    break;
                }
                
            }
            if(!same) break;
            ans+=strs[0][i];
        }
        return ans;
    }
};