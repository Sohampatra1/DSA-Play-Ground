class Solution {
public:
    void dfs(int v, vector<vector<int>> &g, vector<long long> &subTreeSize, vector<bool> &vis){
       
        
        vis[v] = true;

        long long noOfNodes = 0;
        for(auto child : g[v]){
            if(!vis[child]){
                dfs(child,g,subTreeSize,vis);
                   subTreeSize[v] += subTreeSize[child];
            }
             }

            subTreeSize[v] += 1;
        }
            long long minimumFuelCost(vector<vector<int>>& roads, int seats) {

           int n = roads.size() + 1;
         vector<vector<int>> g(n);

            for(auto v : roads){
                g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
            }
        vector<long long> subTreeSize(n,0);
          vector<bool> vis(n,false);
     dfs(0,g,subTreeSize,vis);

           long long cost = 0;
        for(int i = 1;i<n;i++){
               cost += (subTreeSize[i]/seats);
            if(subTreeSize[i]%seats != 0) cost++;
           }
                            return cost;

     }
};