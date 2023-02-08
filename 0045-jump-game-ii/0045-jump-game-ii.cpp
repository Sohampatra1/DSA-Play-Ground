class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
         vector<int>dp(n,-1);
        return minJumps(dp,nums,0);
       
    }
    
    int minJumps(vector<int>& dp, vector<int>& nums, int j)
    {
       
        if(j>=nums.size()-1) return 0;
        int st,en;
        st=j+1;
        
        if(j+nums[j]>=nums.size()-1){
            en=nums.size()-1;
        }
        
        en=j+nums[j];
        
        if(dp[st]==-1)
        
        {
            int temp=100001;
            
            for(int i=st;i<=en;i++){
                temp=min(temp,minJumps(dp,nums,i));
            }
           
        dp[st]=temp;
        }
        
        return 1 + dp[st];
    }
    
};