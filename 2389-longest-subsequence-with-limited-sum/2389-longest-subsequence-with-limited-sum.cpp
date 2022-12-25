class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        sort(nums.begin(), nums.end());

        vector<int> pre(n);
        pre[0] = nums[0];
        for(int i = 1; i< n; i++)
            pre[i] = pre[i-1] + nums[i];
        
        vector<int> ans(m);
        for(int i = 0; i < m; i++)
            {
                int result = upper_bound(pre.begin(), pre.end(), queries[i]) - pre.begin();
                ans[i] = result;
            }

        return ans;
    }
};