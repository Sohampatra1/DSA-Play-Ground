class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size() == 0 or nums.size() == 1 )  return nums.size();
        int res = 0,c =  1;
        for(int i = 1;i < nums.size();i++){
            if(nums[i] - nums[i - 1] == 1)  c++;
             else if(nums[i] - nums[i - 1] == 0){
                 res = max(res,c);
                 continue;
             }
            else c = 1;
            res = max(res,c);
        }
        return res;
    }
};