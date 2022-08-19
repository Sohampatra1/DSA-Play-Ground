class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n=nums.size(), i=0, j=0, k=0;
        unordered_map<int, int> cnt;
        unordered_map<int, int> need;
        for (int i=0; i<n; ++i) ++cnt[nums[i]];
        for (int i=0; i<n; ++i) {
            if (cnt[nums[i]]==0) continue;
            --cnt[nums[i]];
            if (need[nums[i]-1]>0) {
                --need[nums[i]-1];
                ++need[nums[i]];
            } else if (cnt[nums[i]+1]>0 && cnt[nums[i]+2]>0) {
                --cnt[nums[i]+1];
                --cnt[nums[i]+2];
                ++need[nums[i]+2];
            } else return false;
        }
        return true;
    }
};
