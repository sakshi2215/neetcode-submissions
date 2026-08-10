class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int low = 0;
        int high = m*n-1;

        while(low <= high){
            int mid = (low + high)/2;

            int j = (mid % m);
            int i = mid / m;

            if(matrix[i][j]==target) return true;
            else if(matrix[i][j] < target){
                low = mid+1;
            }
            else {
                high = mid -1;
            }

            // cout<<i<<" "<<j<<" ";
            // high = 0;
            // low = mid;
        }
        return false;
    }
};
