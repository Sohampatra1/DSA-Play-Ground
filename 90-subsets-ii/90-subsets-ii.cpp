class Solution {
public:

    void func(int idx , vector<int> &res, set<vector<int>> &ans , vector<int> &nums)
    {
        ans.insert(res);
        for(int i = idx ; i < nums.size() ;i++)
        {
            res.push_back(nums[i]);
            func(i+1 , res, ans, nums);
            res.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>ans;
        vector<vector<int>>ans1;
        vector<int>res;
        sort(nums.begin(),nums.end());
        func(0 , res , ans , nums);
        for(auto i : ans)
            ans1.push_back(i);
        return ans1;
    }
};