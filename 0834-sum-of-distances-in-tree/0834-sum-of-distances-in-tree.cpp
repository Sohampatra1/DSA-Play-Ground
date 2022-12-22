class Solution {
    unordered_map<int, vector<int>> edgeTable;
    vector<int> res, count;
public:

     void dfs(int root, int pre) {
         for (auto i : edgeTable[root]) {
            if (i == pre) continue;
               dfs(i, root);
            count[root] += count[i];
             res[root] += res[i] + count[i];
        }
    }
    void dfs2(int root, int pre) {
        for (auto i : edgeTable[root]) {
            if (i == pre) continue;
              res[i] = res[root] - count[i] + count.size() - count[i];
            dfs2(i, root);
           }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        res.assign(n, 0);
        count.assign(n, 1);
        for(int i=0; i<edges.size(); i++) {
              int u = edges[i][0];
                int v = edges[i][1];
             edgeTable[u].push_back(v);
            edgeTable[v].push_back(u);
        }

        dfs(0, -1);
         dfs2(0, -1);

        return res;
    }
};