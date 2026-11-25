class Solution {
public:
    void solve(string & s, int index, vector<string>&part, vector<vector<string>>&result){
        if(index>=s.size()){
            result.push_back(part);
            return;
        }

        for(int i = index; i< s.size(); i++){
            if(isValid(s, index, i)){
                part.push_back(s.substr(index, i-index+1));
                solve(s, i+1, part, result);
                part.pop_back();
            }
        }
    }

    bool isValid(const string &s, int l, int r){
        while(l < r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>result;
        vector<string>part;
        solve(s, 0, part, result);
        return result;
    }
};
