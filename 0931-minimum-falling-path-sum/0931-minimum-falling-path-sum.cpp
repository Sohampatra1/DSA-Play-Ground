class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        vector<int> dp(matrix.size());
        for(int i=0; i<matrix.size(); i++){
            dp[i] = matrix[matrix.size()-1][i];
        }
               for(int i=matrix.size()-2; i>=0; i--){
            vector<int> temp(matrix.size());
            for(int j=0; j<matrix.size(); j++){
                 int down = dp[j];
                   int leftDiag = INT_MAX;
                int rightDiag = INT_MAX;
                if(j-1>=0)
                    leftDiag = dp[j-1];
                if(j+1<matrix.size())
                    rightDiag = dp[j+1];
             
                temp[j] = matrix[i][j] + min(down, min(leftDiag,rightDiag));
            }
            dp = temp;
        }
         int mini = INT_MAX;
        for(int i=0; i<matrix.size(); i++){
            mini = min(mini,dp[i]);
        }
        return mini;

    }
};