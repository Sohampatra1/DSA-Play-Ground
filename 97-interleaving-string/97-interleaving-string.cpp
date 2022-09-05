class Solution {
public:
    int dp[101][101][201];
    bool solve(string s1,string s2,string s3,int i,int j,int k){
        if(i==s1.size() && j==s2.size() && k==s3.size()){
            return true;
        }
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        bool ans = false;
        if(s1[i]==s3[k]){
            ans = ans|solve(s1,s2,s3,i+1,j,k+1);
        }
        if(s2[j]==s3[k]){
            ans = ans|solve(s1,s2,s3,i,j+1,k+1);
        }
        return dp[i][j][k]=ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        
        memset(dp,-1,sizeof(dp));
        if(s1.size()+s2.size() != s3.size()) return 0;
        return solve(s1,s2,s3,0,0,0);
        
    }
};