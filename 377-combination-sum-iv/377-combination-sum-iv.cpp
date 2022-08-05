class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<uint32_t> dp(target + 1, 0);
        dp[0] = 1;
        for (auto i = 0; i < target; i++) {
            
            if (auto curr = dp[i]; curr > 0) {
               
                for (auto num: nums) {
                    if (auto j = i + num; j <= target) {
                        dp[j] += curr;
                    }
                }
           
               }
         }
        
        return dp[target];
     }
};