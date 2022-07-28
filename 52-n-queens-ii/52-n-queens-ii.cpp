class Solution {
public:
    void place(int col,int n,vector<int> leftRow, vector<int> upperDiag, vector<int> lowerDiag, int& ans){
        if(col==n){
            ans++;
            return;
        }
        
        for(int row=0;row<n;row++){
            if(leftRow[row]==0 && upperDiag[n-1+col-row]==0 && lowerDiag[row+col]==0){  
              leftRow[row]=1;
                upperDiag[n-1+col-row]=1;
                lowerDiag[row+col]=1;
                place(col+1,n,leftRow,upperDiag,lowerDiag,ans);
                leftRow[row]=0;
              upperDiag[n-1+col-row]=0;
                lowerDiag[row+col]=0;
                
          }
        }
        }
    
    int totalNQueens(int n) {
        
    vector<int> leftRow(n,0),upperDiag(n*2-1,0),lowerDiag(n*2-1,0);
         int ans=0;
        place(0,n,leftRow,upperDiag,lowerDiag,ans);
        return ans;
 }
};