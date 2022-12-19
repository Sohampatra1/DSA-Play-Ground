class Solution {
public:

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
    {
        vector<bool> visited(n, 0);
        vector<vector<int>> adj(n);

        for(int i = 0 ; i < edges.size() ; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
  }    
         return DFS(source, destination, adj, visited);
    }

    bool DFS(int node, int destination, vector<vector<int>>& adj, vector<bool>& visited)
    {
        visited[node] = true;

        if(node == destination)
            return true;
             bool f = 0;
        for(int i = 0 ; i < adj[node].size() ; i++)
          {
            if(!visited[adj[node][i]])
            {
        f |= DFS(adj[node][i], destination, adj, visited);
          }
        }
        return f;
    }
};