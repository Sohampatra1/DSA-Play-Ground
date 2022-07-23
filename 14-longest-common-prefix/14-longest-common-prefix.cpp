class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s=strs[0];
        for(int i=0;i<strs.size();i++)
        {
            string t=strs[i];
            for(int j=0;j<s.length();j++)
            {
                if (s[j]!=t[j])
                {
                    s.erase(j,s.length()-j);
                    break;
                }
            }
        }
        return s;
    }
};