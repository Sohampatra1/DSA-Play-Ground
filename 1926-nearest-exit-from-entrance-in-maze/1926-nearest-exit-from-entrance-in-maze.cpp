class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();

        queue<pair<int, pair<int, int> > > q;
        q.push({0, {entrance[0], entrance[1]}});
        
        maze[entrance[0]][entrance[1]] = '+';
        
        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, 1, 0, -1};
        
        while(!q.empty()){
            int row = q.front().second.first;
            int col = q.front().second.second;

            int prev = q.front().first;
            q.pop();

            for(int i = 0; i < 4; i++){
                int newrow = row+delr[i];
                int newcol = col+delc[i];

                if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m){
                    if(maze[newrow][newcol] == '.'){
                        if(newrow == 0 || newrow == n-1 || newcol == 0 || newcol == m-1){
                            return prev+1;
                        }
                        q.push({prev+1, {newrow, newcol}});
                        maze[newrow][newcol] = '+';
                    }
                }
            }
        }
        return -1;
    }
};