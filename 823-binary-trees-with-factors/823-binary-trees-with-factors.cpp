class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int M = 1000000007; 
        sort(arr.begin(),arr.end());
        vector<long long> dp(arr.size(),1);
        map<long,long> m;
        for(int i=0;i<arr.size();i++) m[arr[i]] = i;
        
        for(int i=0;i<arr.size();i++){
            for(int j = 0;j<i;j++){
                if(arr[i]%arr[j] == 0){
                    long div = arr[i]/arr[j];
                    if(m.find(div) != m.end()){
                        dp[i] = (dp[i] + dp[j]*dp[m[div]])%M;
                    }
                }
            }
        }
        long long ans = 0;
        for(auto x: dp){ ans += x;}
        return ans%M;
    }
};