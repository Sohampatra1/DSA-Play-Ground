class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
               priority_queue<int> pq;
            int Minval = INT_MAX;
        for(int i=0; i<nums.size(); i++) {
        if(nums[i] % 2 == 0) {
                   pq.push(nums[i]);
                 Minval=min(Minval, nums[i]);    
              } 
              else{
                pq.push(nums[i]*2);
                  Minval=min(Minval, nums[i]*2);
            }
            }
        int ans = INT_MAX;
         while(!pq.empty()) {
            int top = pq.top();
            pq.pop();
              ans =min(ans, top-Minval);
            if(top%2 != 0) {
               break;
              }
                Minval = min(Minval, top/2);
             pq.push(top/2);
           }
         return ans;
    }
};
