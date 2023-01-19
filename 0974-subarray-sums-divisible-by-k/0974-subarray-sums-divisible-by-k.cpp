class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int count=0;
          int sum=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
              int r=sum%k;
                if(r<0){
                  r=r+k;
            }
            if(mp.find(r)==mp.end()){
                if(r==0){
                    count++;
                  }
                  mp[r]=1;
            }
            else{
               if(r==0){
                    count++;
                }
                   count=count+mp[r];
                mp[r]++;
            }
        }
           return count;
    }
};