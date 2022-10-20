class Solution {
public:
    int hr(vector<int>&nums)
    {
        int n = nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];
        int dp[n];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i=2; i<n; i++)
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];
        vector<int>n1(n-1);
        vector<int>n2(n-1);
        for(int i=0; i<n-1; i++)
            n1.push_back(nums[i]);
        
        for(int i=1; i<n; i++)
            n2.push_back(nums[i]);
        
        int left = hr(n1);
        int right = hr(n2);
        return max(left,right);
    }
};