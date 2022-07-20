#define lli long long int
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        static int mod=1e9+7;
        vector<lli> dp(n+1, 0);
        vector<lli> f(n+1, 0);
        dp[1]=1, f[1]=1;
        lli z=0, sum=0;
        for(int i=2; i<=n; ++i) {
            if(i>forget) {
                z=f[i-forget];
                sum=(sum+z)%mod;
                if(i-forget>delay) {
                    sum=(sum-f[i-forget-delay]+mod)%mod;
                }
            }
            if(i>delay)  {
              f[i]=(dp[i-delay]-sum+mod)%mod;
                dp[i]=(dp[i-1]-z+f[i]+mod)%mod;
            }
            else {
                dp[i]=dp[i-1];
                f[i]=0;
            }
        }
     return dp[n];
    }
};