class Solution {
public:
    vector<vector<int>>dp;
    const int mod=1e9+7;
    int numRollsToTarget(int n, int k, int target) {
        dp=vector<vector<int>>(n+1,vector<int>(target+1,0));
        dp[0][0]=1;
        for(int i=1;i<=target;i++)
        {
            dp[0][i]=0;
        }
        
        for(int i=1;i<=n;i++)dp[i][0]=0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=target;j++)
            {
                for(int h=1;h<=k;h++)
                {
                    if(h<=j)
                    dp[i][j]=(dp[i][j]+dp[i-1][j-h])%mod;
                }
            }
        }
        return dp[n][target];
    }
};