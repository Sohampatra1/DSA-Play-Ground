class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int needed = 1 << k;
        int allOne = needed-1;
        unordered_set<int> got;
        int currHash = 0;
        for(int i=0; i<s.size(); i++) {
            currHash = ((currHash << 1) & allOne) | (s[i]-'0');
            if(i >= k-1 && got.find(currHash) == got.end()) {
                got.insert(currHash);
                needed--;
            }
            if(needed == 0) return true;
        }
        return false;
    }
};