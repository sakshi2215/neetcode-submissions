class Solution {
   public:
    vector<vector<string>> ans;
    vector<bool> column;
    vector<bool> posDiagonal;
    vector<bool> negDiagonal;
    

    void solve(int r, int n, vector<string>&temp){
        //if we reach last column 
        if(r == n){
            ans.push_back(temp);
            return;
        }
        //for each column in that row
        for(int i=0; i<n; i++){
            if(column[i] || posDiagonal[i+r] || negDiagonal[r-i+n]){
                continue;
            }
            column[i] = true;
            posDiagonal[r+i] = true;
            negDiagonal[r-i+n] = true;
            temp[r][i] = 'Q';
            solve(r+1, n, temp);
            column[i] = false;
            posDiagonal[r+i] = false;
            negDiagonal[r-i+n] = false;
            temp[r][i] = '.';
        }

    }

    vector<vector<string>> solveNQueens(int n) {
        column.resize(n, false);
        posDiagonal.resize(2*n, false);
        negDiagonal.resize(2*n, false);
        vector<string>temp(n, string(n, '.'));
        solve(0, n, temp);
        return ans;
    }
};
