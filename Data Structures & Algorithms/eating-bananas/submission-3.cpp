class Solution {
public:
    bool canEat(vector<int>&piles, int h, int speedRate){
        long long hour = 0;
        for(int i=0;i<piles.size();i++){
            hour+= ceil((double)piles[i]/speedRate);
        }
        if(hour<=h) return true;
        else return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int minRate = 1;
        int maxRate = 0;
        int rate =0;

        for(int i=0; i<piles.size();i++){
            maxRate = max(maxRate, piles[i]);
        }

        while(minRate <= maxRate){
            int speedRate = minRate + (maxRate - minRate) / 2;

            if(canEat(piles, h, speedRate)){
                rate = speedRate;
                maxRate = speedRate-1;
            }
            else{
                minRate = speedRate+1;
            }
        }
        return rate;


    }
};
