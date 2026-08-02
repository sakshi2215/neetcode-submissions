class Solution {
   public:
    int memorization(vector<int>& prices, int index, bool canBuy, vector<vector<int>>& dp) {
        if (index >= prices.size()) return 0;

        if (dp[index][canBuy] != -1) return dp[index][canBuy];
        if (canBuy == 1) {
            // choose to buy
            int chooseToBuy = -prices[index] + memorization(prices, index + 1, 0, dp);
            int doesNotBuy = 0 + memorization(prices, index + 1, 1, dp);
            return dp[index][canBuy] = max(chooseToBuy, doesNotBuy);
        } else {
            int chooseToSell = prices[index] + memorization(prices, index + 1, 1, dp);
            int notSell = 0 + memorization(prices, index + 1, 0, dp);
            return dp[index][canBuy] = max(chooseToSell, notSell);
        }
    }

    int tabulationSolution(vector<int>& prices) {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));

        // at index 0, we can choose to buy
        for (int index = prices.size()-1; index >=0; index--) {
            for (int canBuy = 0; canBuy < 2; canBuy++) {
                if (canBuy == 1) {
                    int chooseToBuy = -prices[index] + dp[index + 1][0];
                    int doesNotBuy = 0 + dp[index +1][1];
                    dp[index][canBuy] = max(chooseToBuy, doesNotBuy);
                } else {
                    int chooseToSell = prices[index] + dp[index+1][1]; 
                    int notSell = 0 + dp[index+1][0]; 
                    dp[index][canBuy] = max(chooseToSell, notSell);
                }
            }
        }
        return dp[0][1];
    }
    int recursiveSolution(vector<int>& prices, int index, bool canBuy) {
        // base case
        // if we reached out of index
        if (index >= prices.size()) return 0;

        // if he can buy then

        if (canBuy == 1) {
            // choose to buy
            int chooseToBuy = -prices[index] + recursiveSolution(prices, index + 1, 0);
            int doesNotBuy = 0 + recursiveSolution(prices, index + 1, 1);
            return max(chooseToBuy, doesNotBuy);
        } else {
            int chooseToSell = prices[index] + recursiveSolution(prices, index + 1, 1);
            int notSell = 0 + recursiveSolution(prices, index + 1, 0);
            return max(chooseToSell, notSell);
        }
    }
    int maxProfit(vector<int>& prices) {
        // int profit = 0;
      //  vector<vector<int>> dp(prices.size() + 1, vector<int>(2, -1));

        return tabulationSolution(prices);
    }
};