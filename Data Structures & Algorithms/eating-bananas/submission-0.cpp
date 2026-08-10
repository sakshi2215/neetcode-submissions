class Solution {
public:
    bool isPossible(int k, vector<int>&piles, int h){
        int eatingHour = 0;
        for(int i=0; i<piles.size(); i++){
            eatingHour += ceil((double)piles[i]/k);
        }
        if(eatingHour > h) return false;
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 0;

        for(int i=0; i<piles.size(); i++){
            
            high = max(high, piles[i]);
        }

        int ans =0;

        while(low <= high){
            int mid = (low + high)/2;

            if(isPossible(mid,  piles, h)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};
