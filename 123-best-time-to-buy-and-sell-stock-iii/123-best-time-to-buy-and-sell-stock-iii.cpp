class Solution {
public:
	int solve(int ind,vector<int>& prices,int N,int buy,int trans,vector<vector<vector<int>>>& dp){
		if(ind==N) return 0;
		
		if(trans==2) return 0;
		
		long profit = 0;
		
		if(dp[ind][buy][trans]!=-1) return dp[ind][buy][trans];
		if(buy==0){
			profit = max(-prices[ind] + solve(ind+1,prices,N,1,trans,dp),solve(ind+1,prices,N,0,trans,dp));
		}
		else{
			profit = max(prices[ind] + solve(ind+1,prices,N,0,trans+1,dp),solve(ind+1,prices,N,1,trans,dp));
		}
		
		return dp[ind][buy][trans] = profit;
	}
	int maxProfit(vector<int>& prices) {
		int N = prices.size();
		vector<vector<vector<int>>> dp(N,vector<vector<int>>(2,vector<int>(2,-1)));
		return solve(0,prices,N,0,0,dp);
	}
};