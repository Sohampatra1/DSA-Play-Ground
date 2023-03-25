class Solution {
private:
    void dfs(vector<vector<int>>&adj,vector<bool>&visited,int node,long long &p){
        visited[node]=true;
        p++;

        for(int i=0;i<adj[node].size();i++){
            if(!visited[adj[node].at(i)]) dfs(adj,visited,adj[node].at(i),p);
        }
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long count=0;
        vector<vector<int>>adj(n);
          vector<bool>visited(n,false);

        for(int i=0;i<edges.size();i++){
            int u=edges.at(i)[0];
            int v=edges.at(i)[1];
        adj[u].push_back(v);
            adj[v].push_back(u);
        }
                  long long diff=n;
                  for(int i=0;i<n;i++){
            if(!visited[i]){
                long long p=0;
                dfs(adj,visited,i,p);
                  diff=n-p;
                count+=p*diff;
            }
        }

        return count/2;
    }
};
