class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, int idx){
        if(idx == nums.size()-1){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> s;
        for(int i=idx;i<nums.size();i++){
            if(s.find(nums[i])!=s.end())
                continue;
            s.insert(nums[i]);
             
        swap(nums[i], nums[idx]);
             solve(nums, idx+1);
            swap(nums[i], nums[idx]);
        }
      }
     vector<vector<int>> permuteUnique(vector<int>& nums) {
     
          sort(nums.begin(), nums.end());
        solve(nums, 0);
        return ans;
    }
};