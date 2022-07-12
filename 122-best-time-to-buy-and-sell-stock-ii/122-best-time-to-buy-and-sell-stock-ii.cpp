class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, i = 0, n = prices.size();
        
        while (i < n - 1) {
            while ((i+1 != n) && (prices[i] >= prices[i+1])) i++;
            profit -= prices[i];

            while ((i+1 != n) && (prices[i] < prices[i+1])) i++;
            profit += prices[i];
        }
        
        return profit;
    }
};