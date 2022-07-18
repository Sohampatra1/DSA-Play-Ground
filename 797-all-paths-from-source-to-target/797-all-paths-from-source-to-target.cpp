class Solution {
public:
    
    void f(int ind, vector<vector<int>>& graph, vector<vector<int>>&ans , vector<int>&ds, int n)
    {
         ds.push_back(ind);
        
        if(ind == n-1){
            ans.push_back(ds);
            return;
        }
        
       
        
        for(int i =0;i<graph[ind].size();i++)
        {
            f(graph[ind][i],graph,ans,ds,n);
            ds.pop_back();

        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>ds;
        int n = graph.size();
        
        f(0,graph,ans,ds,n);
        
        return ans;
    }
};