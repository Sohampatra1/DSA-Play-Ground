class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int start = 0;
        bool res = false;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                res = true;
            }
            if(nums[i]<1){
                start++;
            }
        }
        if(!res){
            return 1;
        }
        int j = 1;
        for(int i=start;i<n;i++){
            if(nums[i]!=j){
                return j;
            }
            if(i+1<n && nums[i]==nums[i+1]){
                j--;
            }
            j++;
        }
        return j;
    }
};