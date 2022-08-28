class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        
        for(int i = 0; i < m; i++){
            int x = 0, y = i;
            vector<int> res;
            while(x < n && y < m){
                res.push_back(mat[x++][y++]);
            }
            sort(res.begin(), res.end());
            int k = 0;
            x = 0, y = i;
            while(x < n && y < m){
               mat[x++][y++] = res[k++];
            }
        }
        for(int j = 1; j < n; j++){
            int x = j, y = 0;
            vector<int> res;
            while(x < n && y < m){
                res.push_back(mat[x++][y++]);
            }
            sort(res.begin(), res.end());
            int k = 0;
            x = j, y = 0;
            while(x < n && y < m){
               mat[x++][y++] = res[k++];
            }
        }
        return mat;
    }
};