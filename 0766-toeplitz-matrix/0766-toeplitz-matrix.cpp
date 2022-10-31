class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        
        int r=matrix.size(),c=matrix[0].size(),i=r-1,j=0;
        while(i>0){
            int temp=i,val=matrix[i][j];
            while(++temp<r and ++j<c){
                if(matrix[temp][j]!=val)
                    return false;
                 }
                       i--;
                     j=0;
             }
           while(j<c){
               int temp=j,val=matrix[i][j];;
                  while(++temp<c and ++i<r){
                     if(matrix[i][temp]!=val)
                     return false;
            }
                i=0;
                j++;
        }
         return true;
    }
};