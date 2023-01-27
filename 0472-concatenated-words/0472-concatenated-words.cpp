class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> st;
        for(auto x: words) st.insert(x);
           vector<string> ans;
         for(auto word: words) {
             int n = word.size();
            vector<int> dp(n + 1);
           dp[0] = 1;
            for(int i=0; i<n; i++) {
                if(!dp[i]) continue;
              for(int j=i+1; j<=n; j++) {
            
                    if(j - i < n and st.count(word.substr(i, j - i))) {
              dp[j] = 1;
                      }
                }
                if(dp[n]) {
                          ans.push_back(word);
                        break;
                         }
                         }
         }
           return ans;
    }
};