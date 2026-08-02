class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mpp;

        for(int i=0; i<strs.size(); i++){
            string sortedtemp = strs[i];
            sort(sortedtemp.begin(), sortedtemp.end());
            mpp[sortedtemp].push_back(strs[i]);     
        }

        vector<vector<string>>ans;
        for(auto nodes: mpp){
            vector<string>temp = nodes.second;
            ans.push_back(temp);
        }
        return ans;
    }
};
