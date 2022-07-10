class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.size();
        
        //First we make a dictionary set to fetch words in O(1)
        unordered_set<string> dictionary;
        for(int i=0; i<wordDict.size(); i++){
            dictionary.insert(wordDict[i]);
        }
        
        //Here we store values. dp[i].first stores if the substring can be partitioned
        //We create a vector of n+1 size and initialize the first index to true
        vector<pair<bool,unordered_set<string>>> dp(n+1);
        for(int i=1; i<=n; i++){
            dp[i].first = false;
        }
        
        //We initilaize this to true for the case that a dictionary word is the entire string
        dp[0].first = true;
        
        for(int i=1; i<=n; i++){
    
            //If dp[i-1] was true, we can start building possible words from the (i-1)st index that are in the dictionary
            if(dp[i-1].first){
                string str = "";
                for(int j=i-1; j<n; j++){
                    str += s[j];
					
					//Check if the string from (i-1)st index to jth index exists in dictionary
                    if(dictionary.count(str)==1){
                        
                        //If we find a matching word, this means that the entire string till j can be partitioned
                        //So we mark it as true and get string possibilities till here using the previous answer
                        dp[j+1].first = true;
    
                        //If the earlier index did not have any string present (Case where first word in string)
                        if(dp[i-1].second.size()==0)
                            dp[j+1].second.insert(str);
                        
                        //Build strings for all possibilities using the last answer
                        else{
                            for(auto& tempS : dp[i-1].second){
                                string newS = tempS + " " + str;
                                dp[j+1].second.insert(newS);
                            }
                        }
                    }
                }
            }
        }
        
        vector<string> ans;
        
        //Return all strings for the string ending at (n-1)st index
        for(auto& str : dp[n].second){
            ans.push_back(str);
        }
        
        return ans;
    }
};