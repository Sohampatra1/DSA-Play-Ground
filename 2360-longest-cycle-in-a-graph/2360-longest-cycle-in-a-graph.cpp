class Solution {
public:
      int longestCycle(vector<int>& edges) {
        vector<bool> visited(edges.size(), false);
           vector<int> level(edges.size(), -1);
          int ans = -1;
          for(int i = 0; i < edges.size(); i++) {
            if(!visited[i])
                ans = max(ans, dfs(i, 0, visited, level, edges));
           }
        return ans;
      }
    int dfs(int cur, int cnt, vector<bool>& visited, vector<int>& level, vector<int>& edges) {
        if(cur == -1) return -1;
           if(visited[cur]) {
             if(level[cur] == -1) return -1;
           else return cnt - level[cur];
        }
        visited[cur] = true;
          level[cur] = cnt;
          int ans = dfs(edges[cur], cnt+1, visited, level, edges);
        level[cur] = -1;
          return ans;
      }
};