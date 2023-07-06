class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minLength = n + 1; 
         int sum = 0;
        int left = 0;
     for (int right = 0; right < n; right++) {
     sum += nums[right];
                while (sum >= target) {
                int currentLength = right - left + 1;
                if (currentLength < minLength) {
                minLength = currentLength;
                            }
            sum -= nums[left];
            left++;
            }
        }
            if (minLength > n) {
            return 0;  
                       }
         return minLength;
        }
};