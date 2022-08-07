class Solution {
public:
    int mod=1000000007;
    int dp[20005][5];
    vector<vector<int>> str={{1},{0,2},{0,1,3,4},{2,4},{0}};
    int solve(int n,int i){
        if(n==1) return 1;
        long long ans=0;
        if(dp[n][i]!=-1) return dp[n][i];
        for(auto x:str[i]){
            ans+=solve(n-1,x)%mod;
        }
        return dp[n][i]=ans%mod;
    }
    int countVowelPermutation(int n) {
        long long count=0;
        memset(dp,-1,sizeof dp);
        for(int i=0;i<=4;i++){
            count=(count+solve(n,i))%mod;
        }
        return count;
    }
};