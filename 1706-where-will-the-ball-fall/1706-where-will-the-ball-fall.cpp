class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
       
       int n=grid.size(),m=grid[0].size();
             vector<int> ans(m);
       for (int j=0;j<m;++j){
          ans[j]=solve(0,j,grid);
       }

         return ans;
    }

    int solve(int i,int j,vector<vector<int>> &grid)
    {
        if (i>=grid.size())
        return j;
 if (j==0 && grid[i][j]==-1)
        return -1;

             if (j==grid[0].size()-1 && grid[i][j]==1)
            return -1;
       if (grid[i][j]==1 && grid[i][j+1]==-1)
             return -1;
  if (grid[i][j]==-1 && grid[i][j-1]==1)
         return -1;

            if (grid[i][j]==1)
                    return solve(i+1,j+1,grid);

                            return solve(i+1,j-1,grid);

    }

};