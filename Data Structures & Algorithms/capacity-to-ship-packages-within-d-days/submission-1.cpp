class Solution {
public:
    bool canShip(vector<int>&weights, int days, int capacity){
        int dDays = 1;
        int weight = weights[0];
        for(int i=1;i<weights.size();i++){
            if(weight + weights[i] > capacity){
                weight = weights[i];
                dDays++;
            }
            else{
                weight+=weights[i];
            }
        }
        return dDays<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0;
        int high = 0;

        for(int i=0;i<weights.size();i++){
            low = max(low, weights[i]);
            high+=weights[i];
        }

        int leastCapacity = 0;

        while(low <= high){
            int capacity = low + (high-low)/2;

            if(canShip(weights, days, capacity)){
                leastCapacity = capacity;
                high = capacity-1;
            }
            else{
                low = capacity+1;
            }
        }
        return leastCapacity;
    }
};