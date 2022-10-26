class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1) return false;
        if(k == 1) return true;
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0;
        for(int i = 0; i<n; ++i) {
            sum += nums[i];
            if(mp.find(sum % k) == mp.end()) {
                mp[sum % k] = i;
            }
            else {
                if(i - mp[sum % k] >= 2) {
                    return true;
                }
            }
        }
        return false;
    }
};