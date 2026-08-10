class Solution {
public:
    bool isPossible(int maxCapacity, int days, vector<int>&weights){
        int currentWeight = 0;
        int currDay = 1;

        for(int i=0; i<weights.size(); i++){
            if(weights[i] > maxCapacity) return false;
            if(currentWeight + weights[i] > maxCapacity){
                currDay++;
                currentWeight = weights[i];
            }
            else{
                currentWeight+=weights[i];
            }
        }
        return currDay <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int low = 1;
        int high = 0;

        for(int i=0; i<weights.size(); i++){
            high+=weights[i];
        }

        int ans = INT_MAX;
        while(low <= high){
            int mid = (low + high)/2;

            if(isPossible(mid, days, weights)){
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