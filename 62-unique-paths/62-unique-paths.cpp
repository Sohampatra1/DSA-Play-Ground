class Solution {
public:
int mm,nn;

int allposspaths(int row,int col,vector<vector<int>> &dp){
    if(row == mm || col == nn){
        return 0;
    }
    
    if(dp[row][col] != 0){
        return dp[row][col];
    }
    if((row == mm-1) && (col == nn-1)){
            return 1;
    }
    
    dp[row][col] += allposspaths(row+1,col,dp);
    dp[row][col] += allposspaths(row,col+1,dp);       
    return dp[row][col];
}

int uniquePaths(int m, int n) {
    mm = m;
    nn = n;
    vector<vector<int>> dp(m,vector<int>(n,0));
    return allposspaths(0,0,dp);
}
};

