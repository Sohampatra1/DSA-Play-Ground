class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n==1)return nums;
        vector<vector<int>>v;
        int start=nums[0][0],end=nums[0][1];
        int i=1;
        while(i<n){
            if(nums[i][0]<=end){
                if(nums[i][1]>end)end=nums[i][1];
                i++;
            }
            else if(nums[i][0]>end){
                v.push_back({start,end});
                start=nums[i][0];
                end=nums[i][1];
                i++;
            }
        }
        v.push_back({start,end});
        return v;
    }
};