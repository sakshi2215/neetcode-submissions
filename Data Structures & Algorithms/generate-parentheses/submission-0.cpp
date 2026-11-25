class Solution {
public:
    bool valid(const string& s) {
        int open = 0;
        for (char c : s) {
            open += (c == '(') ? 1 : -1;
            if (open < 0) return false;
        }
        return open == 0;
    }
    void solve(int n, vector<string>&ans, string temp, int count){
        if(count == 2*n && valid(temp)){
            ans.push_back(temp);
            return;
        }
        if(count >= 2*n) return;
        solve(n, ans, temp +'(',  count+1);
        solve(n, ans, temp+')', count+1);

    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        int pairs = 0;
        int count = 0;
        solve(n, ans, "",  count);
        return ans;
    }
};
