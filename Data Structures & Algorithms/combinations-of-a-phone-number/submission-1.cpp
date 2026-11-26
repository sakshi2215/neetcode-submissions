class Solution {
public:
    void solve(map<char, string>&mpp, string & path, vector<string>&ans, string & digits, int index){

        if(index >= digits.size()){
            ans.push_back(path);
            return;
        }

        string choice = mpp[digits[index]];
        for(int i=0; i<choice.size(); i++){
            path+=choice[i];
            solve(mpp, path, ans, digits, index+1);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        map<char, string>mpp;
        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz";

        string path= "";
        vector<string>ans;
        solve(mpp, path, ans, digits, 0);
        return ans;
    }
};
