class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        
        vector<pair<int, int>> arr1;
        vector<pair<int, int>> arr2;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(img1[i][j] == 1) {
                    arr1.push_back({i, j});
                }
                if(img2[i][j] == 1) {
                    arr2.push_back({i, j});
                }
            }
        }
        
        map<pair<int, int>, int> mp;
        
        int ans = 0;
        for(auto it1: arr1) {
            for(auto it2: arr2) {
                mp[{it2.first - it1.first, it2.second - it1.second}]++;
                ans = max(ans, mp[{it2.first - it1.first, it2.second - it1.second}]);
            }
        }
        return ans;
    }
};