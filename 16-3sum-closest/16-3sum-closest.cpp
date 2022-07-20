class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int x = INT_MAX;
        for(int i=0;i<n-2;i++)
        {
            int left = i+1;
            int right = n-1;
            while(left<right)
            {
                int diff = target - nums[i] - nums[left] - nums[right];
                if(diff==0)
                    return target;
                if(abs(diff)<abs(x))
                    x = diff;
                
                if(diff<0)
                    right--;
                else
                    left++;
            }
        }
        return target-x;
    }
};