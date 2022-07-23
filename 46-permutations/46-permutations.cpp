class Solution {
public:
    void dfs(vector<int> orig, int index, vector<vector<int>> &add){
        if(index == orig.size() - 1){
            add.push_back(orig);
            return;
        }

        for(int i = index; i<orig.size(); i++){
            swap(orig[index], orig[i]);
            dfs(orig, index + 1, add);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> t;
        dfs(nums, 0, t);
        return t;
    }
};
