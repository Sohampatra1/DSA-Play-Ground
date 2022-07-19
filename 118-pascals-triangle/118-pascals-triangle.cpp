class Solution {
public:
    vector<vector<int>> sum;
    vector<vector<int>> generate(int numRows) {
        for(int i = 0; i<numRows; i++){
            vector<int> rows(i+1,1);
            for(int j = 1;j<i;j++){
                rows[j] = sum[i-1][j]+sum[i-1][j-1]; 
            }
            sum.push_back(rows);
        }
        return sum;
    }
};