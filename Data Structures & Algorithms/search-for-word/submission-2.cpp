class Solution {
public: 
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int n , int m, vector<vector<bool>>&visited, int index){
        if(index == word.length()) return true;
        if(i >= n || i< 0 || j >=m || j< 0 || board[i][j]!=word[index] || visited[i][j]){
            return false;
        }
        visited[i][j]=true;

        bool result = dfs(board, word, i+1, j, n, m, visited, index+1) ||
                        dfs(board, word, i-1, j, n, m, visited,index+1) ||
                        dfs(board, word, i, j+1, n, m, visited, index+1) ||
                        dfs(board, word, i, j-1, n, m,visited, index+1);
        visited[i][j] = false;

        return result;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m, false));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==word[0]){
                    bool ans = dfs(board, word, i, j , n,  m, visited, 0);
                    if(ans) return true;
                }
            }
        }
        return false;
    }
};
