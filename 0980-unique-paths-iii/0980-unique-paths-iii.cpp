class Solution {
    int paths=0;
      int starting_Pointx=0;
      int starting_Pointy=0;
   
 int end_Pointx=0;
      int end_Pointy=0;
private:
     void uniquePathCount(int r, int c,vector<vector<int>>& grid,vector<vector<int>>visited,int eCount,int n,int m){
         if( r<0 || c<0 || r>=n || c>=m)
         return;
         if(visited[r][c]==-1 || grid[r][c]==-1){
            return;
         }
         if(r==end_Pointx && c==end_Pointy){
            if(eCount==0){
                paths++;
            }
            return;
         }
         eCount--;
         visited[r][c]=-1;
          uniquePathCount(r+1,c,grid,visited,eCount,n,m);
         uniquePathCount(r,c+1,grid,visited,eCount,n,m);
           uniquePathCount(r-1,c,grid,visited,eCount,n,m);
             uniquePathCount(r,c-1,grid,visited,eCount,n,m);
     }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size();
          int m=grid[0].size();
       vector<vector<int>>visited(n,vector<int>(m, 0));
       int emptyCount=0;

       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(grid[i][j]==0 || grid[i][j]==1){
                   emptyCount++;
               }
               if(grid[i][j]==1){
                   starting_Pointx=i;
                   starting_Pointy=j;
               } 
               if(grid[i][j]==2){
                     end_Pointx=i;
       end_Pointy=j;
               }
              }
             } 
  uniquePathCount(starting_Pointx,starting_Pointy,grid,visited,emptyCount,n,m);
     return paths;

 }
};