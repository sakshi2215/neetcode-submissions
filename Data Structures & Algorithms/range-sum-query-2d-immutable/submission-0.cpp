class NumMatrix {
public:
    vector<vector< int>>prefixSum;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        prefixSum = vector<vector<int>>(n, vector<int>(m, 0));
        
        for(int i=0; i<n; i++){
            int rowSum = 0;
            for(int j=0; j<m; j++){
                rowSum+=matrix[i][j];
                if(i==0){
                    prefixSum[i][j] = rowSum;
                }
                else{
                    prefixSum[i][j] = rowSum + prefixSum[i-1][j];
                }

            }
        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {

        int ans = prefixSum[row2][col2];

        if(row1 > 0){
            ans-= prefixSum[row1-1][col2];
        }
        if(col1 > 0){
            ans-=prefixSum[row2][col1-1];
        }
        if(row1>0 && col1 > 0){
            ans+=prefixSum[row1 - 1][col1 - 1];
        }
        return ans;
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */