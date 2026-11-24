class Solution {
public:
    void solve(int n, int k, int index, vector<int>&temp, vector<vector<int>>&ans, vector<int>&number){
        if(temp.size()==k) {
            ans.push_back(temp);
            return;
        }
        if(index >= number.size()) return;

        temp.push_back(number[index]);
        solve(n, k, index+1, temp, ans, number);
        temp.pop_back();
        solve(n, k, index+1, temp, ans, number);

    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>number(n);
        for(int i=0; i<n;i++){
            number[i]= i+1;
        }
        vector<int>temp;
        solve(n, k, 0, temp, ans, number);
        return ans;
    }
};