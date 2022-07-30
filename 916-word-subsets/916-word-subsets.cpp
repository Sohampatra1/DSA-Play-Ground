class Solution {
public:
     vector<int> giveMeFreq(string s)
    {
        vector<int> freq(26,0);
        for(int i = 0; i < s.length(); i++)
        {
            freq[s[i] - 'a']++;
        }
        return freq;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int>max_freq(26,0);
        vector<int>freq(26,0);
        for(auto &x:words2){
            freq=giveMeFreq(x);
            for(int i=0;i<26;i++){
                max_freq[i]=max(max_freq[i],freq[i]);
            }
            
        }
        vector<string>ans;
        for(auto&x:words1){
            freq=giveMeFreq(x);
            for(int i=0;i<26;i++){
                if(max_freq[i]>freq[i]){
                    break;
                }
                if(i==25){
                    ans.push_back(x);
                }
            }
        }return ans;
    }
};
