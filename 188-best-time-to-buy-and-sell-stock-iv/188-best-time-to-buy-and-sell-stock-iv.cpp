class Solution {
public:
    int maxProfit(int k, vector<int>& cost) {
        int i, j;  
        int len = cost.size();     
        vector<pair<int, int>> dp(len + 1);
        vector<pair<int, int>> temp(len + 1);
        
        dp[0].first = 0;
        dp[0].second = -1e7;
        for(i = 1; i <= len; i++){
            dp[i].second = max(dp[i - 1].second, dp[i - 1].first - cost[i - 1]);
            dp[i].first = 0;
        }
        
        for(i = 1; i <= k; i++){
            temp = dp;
            for(j = 1; j <= len; j++){
                temp[j].first = max(temp[j - 1].first, dp[j - 1].second + cost[j - 1]);
                temp[j].second = max(temp[j - 1].second, temp[j - 1].first - cost[j - 1]);
            }
            dp = temp;
        }
        return dp[len].first;
    }
};