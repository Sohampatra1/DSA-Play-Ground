class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int currMin = prices[0], maxGain = 0;
        for(int i=1;i<size;i++){
            maxGain = max(maxGain, prices[i]-currMin);
            currMin = min(currMin, prices[i]);
        }
        return maxGain;
    }
};