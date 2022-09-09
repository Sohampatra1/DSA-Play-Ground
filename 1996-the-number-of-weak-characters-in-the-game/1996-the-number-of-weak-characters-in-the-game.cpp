class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b) {
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), comp);
        int n = properties.size();
        
        int mr = properties[n-1][1], ans = 0;
        for(int i = n-2; i >= 0; i--) {
            if(mr > properties[i][1]) ++ans;
            mr = max(mr, properties[i][1]);
        }
        
        return ans;
    }
};