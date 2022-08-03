class Solution {
public:
    int dfs(int i,int j, vector<vector<int>>& matrix, int prev, vector<vector<int>> &dp){
        
        if(i<0 or i>=matrix.size() or j<0 or j>=matrix[0].size()){
            return 0;
        }
        if(prev>=matrix[i][j]){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int up=1+dfs(i-1,j,matrix,matrix[i][j],dp);
        int down=1+dfs(i+1,j,matrix,matrix[i][j],dp);
        int left=1+dfs(i,j-1,matrix,matrix[i][j],dp);
        int right=1+dfs(i,j+1,matrix,matrix[i][j],dp);
        
        return dp[i][j]=max(up,max(down,max(left,right)));
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int mx=INT_MIN;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                mx=max(mx,dfs(i,j,matrix,-1,dp));
            }
        }
        return mx;
    }
};