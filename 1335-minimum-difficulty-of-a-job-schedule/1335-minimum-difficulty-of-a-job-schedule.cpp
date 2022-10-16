class Solution {
public:
    int n;
    int difficulty(int ind, int cut, vector<int>&jobs, vector<vector<int>>&dp)
    {
        if(cut==1)
        {
            int maxi = INT_MIN;
            while(ind<n)    maxi = max(maxi, jobs[ind++]);
            return maxi;
        }
        if(dp[cut][ind] != -1)    return dp[cut][ind];
        int res = INT_MAX, mxx = 0;
        for(int i=ind;i<n-cut+1;i++)
        {
            mxx = max(mxx, jobs[i]);
            res = min(res, mxx + difficulty(i+1, cut-1, jobs, dp));
        }
        return dp[cut][ind] = res;
    }
    int minDifficulty(vector<int>& jobs, int d) {
        n = jobs.size();
        if(n<d)   return -1;
        vector<vector<int>>dp(d+1, vector<int>(n,-1));
        return difficulty(0,d,jobs,dp);
    }
};