class Solution {
public:
     int singleNumber(vector<int>& nums) {
        int n=0;
         
         int len=nums.size();
       
          for(int i=0;i<len;i++)
        {
            n=n^nums[i];
            }
        return n;
    }
};