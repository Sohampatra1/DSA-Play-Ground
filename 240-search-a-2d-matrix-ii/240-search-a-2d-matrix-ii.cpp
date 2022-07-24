class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r =0;  // we intialized the row at 0
        int c =matrix[0].size()-1;  // and col at the end of the first row 
        
        while(r<matrix.size() and c>=0){ 
            if(matrix[r][c]==target){  // if we found the target return true
                return true;
            }
            else if(matrix[r][c]>target){ // if element ids greater than the target
                c--;  // we move backwards in the same row
            }
            else{
                r++;  // else element is lesser than the target 
            }         // we move downwards in the same column
        }
        return false;  
    }
};