class Solution {
public:
    
    int m, n;
    
    vector<int> dx{1, -1, 0, 0};
    vector<int> dy{0, 0, 1, -1};
    vector<vector<bool>> atlantic;
    vector<vector<bool>> pacific;
    
    bool isValid(int x, int y)
    {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }
    
    void dfs(vector<vector<int>>& heights, vector<vector<int>> &ans, vector<vector<bool>> &currOcean, int x, int y)
    {
        if(currOcean[x][y])
            return;
        
        currOcean[x][y] = true;
        
        if(atlantic[x][y] && pacific[x][y])
            ans.push_back({x, y});
        
        for(int i=0;i<4;i++)
        {
            int newX = x + dx[i], newY = y + dy[i];
            if(isValid(newX, newY) && heights[newX][newY] >= heights[x][y])
            {
                dfs(heights, ans, currOcean, newX, newY);
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vector<vector<int>> ans;
        atlantic = pacific = vector<vector<bool> >(m, vector<bool>(n, false));
        
        for(int i=0;i<m;i++)
        {
            dfs(heights, ans, pacific, i, 0);
            dfs(heights, ans, atlantic, i, n - 1);
        }
        for(int j=0;j<n;j++)
        {
            dfs(heights, ans, pacific, 0, j);
            dfs(heights, ans, atlantic, m - 1, j);
        }
        return ans;
    }
};