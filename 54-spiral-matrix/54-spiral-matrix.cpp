class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int row = matrix.size();
        int col = matrix[0].size();
        int up = 0;
        int left = col-1;
        int down = row-1;
        int size = row*col;
        int right = 0;
        while(left>=right && up<=down){
            for(int i=right; i<=left; i++){
                if(size == result.size()){
                    break;
                }
                result.push_back(matrix[up][i]);
            }
            up++;
            for(int i=up; i<=down; i++){
                if(size == result.size()){
                    break;
                }
                result.push_back(matrix[i][left]);
            }
            left--;
            for(int i=left; i>=right; i--){
                if(size == result.size()){
                    break;
                }
                result.push_back(matrix[down][i]);
            }
            down--;
            for(int i=down; i>=up; i--){
                if(size == result.size()){
                    break;
                }
                result.push_back(matrix[i][right]);
            }
            right++;
        }
        return result;
    }
};