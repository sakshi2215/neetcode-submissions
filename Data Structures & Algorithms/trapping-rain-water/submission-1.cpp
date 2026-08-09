class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        vector<int>pme(n);
        vector<int>nme(n);
        pme[0] = height[0];
        for(int i=1; i<n; i++){
            pme[i] = max(pme[i-1], height[i]);
            cout<<pme[i]<<" ";
        }
        nme[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--){
            nme[i] = max(nme[i+1], height[i]);
        }
        int ans =0;
        for(int i=0; i<n; i++){
            ans+= (min(nme[i], pme[i])-height[i]);
        }
        return ans;
    }
};
