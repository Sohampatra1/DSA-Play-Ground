class Solution {
public:
    int subarrays(vector<int>nums, int mid, int m){
        int n = nums.size();
        int count = 1;
        int sum=0;
        for(int i=0; i<n;i++){
            if(sum+nums[i]>mid){
                count++;
                sum = nums[i];
            }
            else{
                sum = sum+nums[i];
            }
        }
        return count;
    }
    int splitArray(vector<int>& nums, int m) {
        int start = *max_element(nums.begin(),nums.end()); 
        int end = accumulate(nums.begin(),nums.end(),0);
        int res;
        while(start<=end){
            int mid = start + (end-start)/2;
            int n = subarrays(nums,mid,m);
            if(n>m){
                start = mid+1;  
            }
            else{
                res = mid;
                end = mid-1;
            }
        }
        return res;
    }
};