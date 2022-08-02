class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int start = 0, end = nums.size()-1;
		vector<int> ans(2);

		while(start < end){
			int sum = nums[start]+nums[end];
			if(sum == target){
				ans[0] = start+1 , ans[1] = end+1;
				return ans;
			}
			if(sum > target){
				end--;
			}
			else{
				start++;
			}
		}

		return ans;
	}
};
