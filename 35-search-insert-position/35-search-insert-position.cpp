class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;
        int mid = (s+e)/2;
        
        while(s<=e){
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) e = mid - 1;
            else if(nums[mid] < target) s = mid + 1;
            mid = (s+e)/2;
        }
        if(target < nums[mid]) return mid;
        return mid + 1;
    }
};