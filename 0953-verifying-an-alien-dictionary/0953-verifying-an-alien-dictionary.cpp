class Solution {
public:
    map<char,int> mp;
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0;i<26;i++)
        {
               mp[order[i]] = i+1;
             }

        for(int i=1;i<words.size();i++)
           {
              if(!check(words[i-1],words[i]))
                return false;
           }
     return true;
    }

    bool check(string a, string b)
    {            
        int n = min(a.size(),b.size());
        for(int i=0;i<n;i++)
        {
            if(mp[a[i]] < mp[b[i]])
                    return true;
                 else if(a[i]==b[i])
                continue;
            if(mp[a[i]] > mp[b[i]]){
                return false;
            }
           }
        if(b.size() < a.size())
            {
            return false;
        }
            return true;
    }
};