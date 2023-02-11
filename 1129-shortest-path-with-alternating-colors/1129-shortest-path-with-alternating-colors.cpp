class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        unordered_map<int, vector<int>>r, b;
       for(int i = 0; i < redEdges.size(); i++){
            r[redEdges[i][0]].push_back(redEdges[i][1]);
               }
        
        for(int i = 0; i < blueEdges.size(); i++){
            b[blueEdges[i][0]].push_back(blueEdges[i][1]);
            }
        
        vector<int>ans1(n, INT_MAX), ans2(n, INT_MAX); 
         priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        
        pq.push({0,0,0}); 
        pq.push({0,0,1}); 
         while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
             if(t[2] == 0 && ans1[t[1]] <= t[0]){
                continue;
            }
           
            if(t[2] == 1 && ans2[t[1]] <= t[0]){ 
                continue;
            }
            
            if(t[2] == 0)
            {   
                ans1[t[1]] = t[0];
                for(auto x: b[t[1]]){
                   
                    if(ans2[x] > ans1[t[1]]+1){
                        pq.push({ans1[t[1]]+1, x, 1});
                    }
                }
            }
            if(t[2] == 1){   
                ans2[t[1]] = t[0];
                for(auto x: r[t[1]]){
                    if(ans1[x] > ans2[t[1]]+1){
                        pq.push({ans2[t[1]]+1, x, 0});
                    }
                }
                   }
                   }
        
        vector<int>ans(n); 
        for(int i = 0; i < n; i++){
            if(ans1[i] == INT_MAX && ans2[i] == INT_MAX){
                ans[i] = -1;
            }
            else{
                ans[i] = min(ans1[i], ans2[i]);
            }
               }
        
              return ans;
        }
};