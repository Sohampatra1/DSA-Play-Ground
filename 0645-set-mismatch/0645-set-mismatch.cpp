class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        int n = nums.size(); vector<int> res(2, 0);
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 1; ++i)
            if(nums[i] == nums[i + 1]) res[0] = nums[i], nums[i] = 0;
        int sum = nums.size();
        
          for(int i = 0; i < n; ++i) sum ^= i ^ nums[i];
          res[1] = sum;
           return res;
    }
};