class Solution {
public:
    pair<int,int> findrc(int curr,int  n){
        pair<int, int> ret;
        int r = n - (curr-1) / n-1;
       int c = (curr-1 )%n;
        if(r%2 == n%2){
            ret.first= r;
             ret.second = n-1-c;
          }
        else{
            ret.first= r;
             ret.second =c;
        }
        return ret;
      }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
         queue<int> q;
           int visited[n][n];
          for(int i =0; i<n; i++ ){
            for(int j= 0; j<n; j++ ){
                visited[i][j]= false ;
            }
        }
        q.push(1);
        visited[n-1][0] = true;
            int step = 0;
         while(q.size()!=0)
        {
            int size = q.size();
            for(int i=0; i<size; i++){
                 int x = q.front();
                q.pop();
                if(x== n*n) return step;
                
                for(int k = 1; k<=6; k++){
                    if(k+x > n*n) break;
                     pair<int,int> pos = findrc(k+x , n);
                    int r = pos.first;
                      int c = pos.second;
                    if(visited[r][c]== true) continue;
                        visited[r][c] = true;
                    if(board[r][c]==-1)
                    {
                        q.push(k+x);
                    }
                    else{
                        q.push(board[r][c]);
                    }
                    }
              }
              step++;   
        }
          return -1;
       }
};