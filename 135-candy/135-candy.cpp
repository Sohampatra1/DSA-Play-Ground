class Solution {
public:
    int direction(int x, int y) {
        if (x == y) return 0;
        return (x > y ? -1 : 1);
    }
    
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int i = 0, prev = 1;
        int ans = 1;
        while (i + 1 < n) {
            int run = 1, dir = direction(ratings[i], ratings[i + 1]);
            while (i + 1 < n && dir == direction(ratings[i], ratings[i + 1])) {
                run++;
                i++;
            }
            if (dir == 0) {
                ans += run;
                ans -= 1;
                prev = 1;
            } else {
                ans += run * (run + 1) / 2;
                if (dir == -1) {
                    ans -= min(prev, run);
                } else {
                    ans -= 1;
                }
                prev = run;
            }
        }
        return ans;
    }
};