class Solution {
public:
    vector<int> dp;
    int fun(int n){
        if(n==0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int ans = INT_MAX;
        for(int i=1;i<=sqrt(n);i++){
            int sq = i*i;
            int curCnt = 1+ fun(n-sq);
            ans = min(curCnt,ans);
        }
        return dp[n] = ans;
    }
    int numSquares(int n) {
        dp.resize(n+1,-1);
        return fun(n);
    }
};