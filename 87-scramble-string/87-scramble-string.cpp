class Solution {
public:
    unordered_map<string, bool>dp;
    bool solve(string s1, string s2)
    {
        if(s1 == s2)
            return true;
        if(s1.length() <= 1)
            return false;
        string temp = s1+""+s2;
        if(dp.find(temp) != dp.end())
            return dp[temp];
        bool flag = false;
        int n = s1.length();
        bool cond1=false, cond2=false;
        for(int k=1; k<=n-1; k++)
        {
            if(solve(s1.substr(0, k), s2.substr(n-k, k)) && (solve(s1.substr(k, n-k), s2.substr(0, n-k))))
                cond1= true;
            if(solve(s1.substr(0, k), s2.substr(0, k)) && (solve(s1.substr(k, n-k), s2.substr(k, n-k))))
                cond2 = true;
            if(cond1 || cond2)
            {
                flag = true;
                break;
            }
        }
        return dp[temp] = flag;
    }
    bool isScramble(string s1, string s2) {
        if(s1 == s2)
            return true;
        if(s1.length() != s2.length())
            return false;
        if(s1.length() <= 1)
            return false;
        return solve(s1, s2);
    }
};