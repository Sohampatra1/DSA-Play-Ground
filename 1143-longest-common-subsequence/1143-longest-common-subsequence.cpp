class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
                short m = text1.size(), n = text2.size();
        short dp[2][n+1];
        dp[1][0] = 0;
        for(short j = 0; j<= n; j++) dp[0][j]= 0;
        for(short i = 1; i <= m; ++i)
            for(short j = 1; j <= n; ++j) 
                dp[i%2][j] = text1[i-1] == text2[j-1] ? dp[(i-1)%2][j-1] + 1 : max(dp[(i-1)%2][j], dp[i%2][j-1]);
        return dp[(m)%2][n];
        
        
    }
};