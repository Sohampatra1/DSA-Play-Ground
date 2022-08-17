class Solution {
    string convert(string &s){
        string ans="";
        vector<string> con
            = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(auto &c: s)
            ans+=con[c-'a'];
        return ans;
    }
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> cache;
        for(auto &w: words)
            cache.insert(convert(w));
        return cache.size();
        
    }
};