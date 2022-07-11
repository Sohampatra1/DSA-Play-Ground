class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        
        int l=0;
        int len=path.length();
        while(l<len){
            
            while(l<len and path[l]=='/')
                l++;
            string tmp;
            while(l<len and path[l]!='/')
                tmp.push_back(path[l++]);
            if(tmp==".")
                continue;
            else if(tmp=="..")
            {
                if(!s.empty())
                    s.pop();
            }
            else if(tmp.length())
                s.push(tmp);

        }
        vector<string> v;
    
        while(!s.empty())
        {
            v.push_back(s.top());
            s.pop();
        }

        int sz=v.size();
        string ans;

        while(sz--)
        {
            ans+="/";
            ans+=v[sz];
        }
        if(ans.length()==0)
            return "/";
        return ans;
    }
};