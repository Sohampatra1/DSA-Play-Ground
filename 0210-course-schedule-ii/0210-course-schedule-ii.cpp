class Solution {
public:
    
    vector<int> topology(vector<int>adj[] , int n)
    {
        queue<int>q;
          vector<int>topo;
            vector<int>indegree(n,0);
          for(int i=0 ; i<n; i++)
        {
           for(auto j:adj[i])
                indegree[j]++;
        }
        
          for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        
        while(!q.empty())
        {
            int node=q.front();
            topo.push_back(node);
            q.pop();
            for(auto i:adj[node])
            {
                indegree[i]--;
                if(indegree[i]==0)
                 q.push(i);
                }
        }
        if(topo.size()==n)
            return topo;
                 cout<<topo.size();
        return {};
       }
    
      vector<int> findOrder(int n, vector<vector<int>>& pre) {    
        vector<int>adj[n];
        for(auto i:pre)
        {
            adj[i[1]].push_back(i[0]);
        }
        
        vector<int>ans=topology(adj , n);
        return ans;
        
    }
};