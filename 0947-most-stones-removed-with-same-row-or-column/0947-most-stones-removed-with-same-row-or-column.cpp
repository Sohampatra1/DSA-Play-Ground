class Solution {
public:
    vector<bool> vis;
    bool val(vector<int> &a, vector<int> &b){
        if(a[0] == b[0] || a[1] == b[1]) return 1;
        return 0;
    }
    void dfs(int i,vector<vector<int>>& stones){
        vis[i] = 1;
        for(int j=0;j<stones.size();j++){
            if(vis[j]) continue;
            if(val(stones[i],stones[j])) dfs(j,stones);
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        vis.resize(stones.size(),0);
        int grp=0;
        for(int i=0;i<stones.size();i++){
            if(vis[i]) continue;
            dfs(i,stones);
            grp++;
        }
        return stones.size()-grp;
    }
};