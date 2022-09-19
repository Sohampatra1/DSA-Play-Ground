class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> res;
        for(auto sent:paths)
        {
            string s = "";
            int i = 0;
            for(i = 0;i<sent.length();i++)
            {
                if(sent[i]==' ') 
                {
                    s+='/';
                    i++;
                    break;
                }
                else s+=sent[i];
            }
            string t = "";
            while(i<sent.length())
            {
                if(i<sent.length() && sent[i]=='(')
                {
                    i++;
                    string res = "";
                    while(i<sent.length() && sent[i]!=')')
                    {
                        res+=sent[i];
                        i++;
                    }
                    i+=2;
                    mp[res].push_back(s+t);
                    t="";
                }
                else
                {
                    t+=sent[i];
                    i++;
                }
            }
        }
        for(auto i:mp) 
        {
            if(i.second.size() > 1) res.push_back(i.second);
        }
        return res;
    }
};