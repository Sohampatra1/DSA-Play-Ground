class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> hash;
        for(auto num: arr) {
            if(hash.find(num) != hash.end()) {
                hash[num]++;
            }
            else {
                hash.insert({num, 1});
            }
        }
        set<int> unique;
        for(auto pair : hash) {
            if(unique.find(pair.second) != unique.end()) {
                return false;
            }
            unique.insert(pair.second);
        }
        return true;
    }
};