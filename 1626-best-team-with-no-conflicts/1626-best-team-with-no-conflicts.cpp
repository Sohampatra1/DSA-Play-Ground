class Solution 
{
public:
    int dp[1011][1011];
       int f(int i, int prevAge, vector<pair<int,int>> &v)
                                                    {
        int sum=0;
         if(i==v.size()) return sum;
          if(dp[i][prevAge]!=-1) return dp[i][prevAge];
         if(v[i].second>=prevAge) sum+=max(v[i].first+f(i+1,v[i].second,v), f(i+1,prevAge,v));
            else sum+=f(i+1,prevAge,v);
        return dp[i][prevAge]=sum; }
      int bestTeamScore(vector<int>& scores, vector<int>& ages) 
        {
        memset(dp,-1,sizeof(dp));
           int n=scores.size();
         vector<pair<int,int>> v;
           for(int x=0; x<n; x++)
        {
             v.push_back({scores[x],ages[x]});
                                   }
        sort(v.begin(),v.end());
           return f(0,0,v);
                                   }
};