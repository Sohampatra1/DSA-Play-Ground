class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int ans = 0;
        
        for(int i=0;i<colors.size();i++){
            
            int curSum = neededTime[i];
            int maxVal = neededTime[i];
            int k = i+1;
            
            while(k<colors.size() && colors[k]==colors[i]){
                curSum += neededTime[k];
                maxVal = max(maxVal, neededTime[k]);
                k++;
            }
            
            curSum -= maxVal;
            ans += curSum;
            i = k-1;
        }
        
        return ans;
    }
};