class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>pse(n);
        vector<int>nse(n);

        pse[0] = height[0];
        for(int i=1; i<n; i++){
            pse[i] = max(pse[i-1], height[i]);
        }
        nse[n-1] = height[n-1];
        for(int i= n-2; i>=0; i--){
            nse[i] = max(nse[i+1], height[i]);
        }

        int sum= 0;
        for(int i=0; i<n; i++){
            sum += min(pse[i], nse[i])-height[i];
        }
        return sum;

    }
};
