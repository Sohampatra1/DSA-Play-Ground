class Solution {
public:
bool isvalid(string s)
{
if(s[0] == '0')
return false;

    int val = stoi(s);
    return val <= 255;
}

void helper(string s,int i, int par,string ans,vector<string> &res)
{
    if(s.size() == i || par == 4)
    {
        if(s.size() == i && par == 4)
        {
            ans = ans.substr(0 , ans.size() - 1);
            res.push_back(ans);
        }
        return;
    }
    helper(s, i+1, par+1, ans+s[i]+".", res);
    
    string st = s.substr(i, 2);
    if(i+2 <= s.size() && isvalid(st))
        helper(s, i+2, par+1, ans + st +".", res);
    
    string str = s.substr(i, 3);
    if(i+3 <= s.size() && isvalid(str))
        helper(s, i+3, par+1, ans + str +".", res);
}

vector<string> restoreIpAddresses(string s) 
{
    vector<string> res;
    string ans = ""; 
    
    helper(s, 0, 0, ans, res);
    
    return res;
}
};

