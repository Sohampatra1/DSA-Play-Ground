class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
    
        int head=0,tail=0,len=nums.size(),answer=INT_MAX,sum=0;
         
        while(tail<len){
            // processing window
            sum+=nums[tail];
            // expanding window
            if(sum<target){
                tail++;
            }
            // contracting the window
            else{
                while(sum>=target){
                    int windowSize=tail-head+1;
                    answer=min(answer,windowSize);
                    sum-=nums[head];
                    head++;
                }
                tail++;  
            }
            
           
        }
        
     if(answer==INT_MAX)return 0;
            else return answer;
    }
};
