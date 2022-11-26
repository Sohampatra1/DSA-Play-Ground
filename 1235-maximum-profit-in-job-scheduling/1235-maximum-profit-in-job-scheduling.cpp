class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        
        if(a[0]==b[0]){
            return a[1]<b[1];
        }
        return a[0]<b[0];
    }
    int find(vector<vector<int>>&v,int x,int lo){
        int ans=-1;
        int hi=v.size()-1;
        while(lo<=hi){
            int mid=(lo+(hi-lo)/2);
            if(v[mid][0]>=x){
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
    int solve(int i,vector<vector<int>>&v,vector<int>&dp){
        if(i==v.size()){
            return 0;
        }
        if(dp[i]!=-1)
        return dp[i];
        int ex=solve(i+1,v,dp);
        int in=v[i][2];
        int next=find(v,v[i][1],i+1);
        if(next!=-1)
        in+=solve(next,v,dp);
        return dp[i]=max(in,ex);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> v;
        int n=profit.size();
        for(int i=0;i<n;i++){
            v.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(v.begin(),v.end(),comp);
        vector<int> dp(n,-1);
        return solve(0,v,dp);
    }
};