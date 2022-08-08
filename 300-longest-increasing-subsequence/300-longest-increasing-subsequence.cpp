class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        int dp[n+1];
        memset(dp, 0, sizeof dp);
        map<int,int> maxLNum;
        
        for(int i=n-1; i>=0; i--){
            int maxL = 0;
            auto itr = maxLNum.rbegin();
            while(itr!=maxLNum.rend()){
                if(itr->second>nums[i]){
                    maxL = itr->first;
                    break;
                }
                itr++;
            }
            dp[i] = maxL+1;
            maxLNum[dp[i]] = nums[i];
        }
        
        return *max_element(dp, dp+n);
       
    }
};