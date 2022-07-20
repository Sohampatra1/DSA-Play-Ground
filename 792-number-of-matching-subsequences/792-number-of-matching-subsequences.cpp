class Solution {
public:
    bool sol(string s,string word)
    {
        int i=0,j=0,ns=s.size(),nw=word.size();
        while(i<ns&&j<nw)
        {
            if(s[i]==word[j])
            {
                i++,j++;
            }
            else
                i++;
        }
        return (j==nw);
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int n=0;
        int len=words.size();
        unordered_map<string,int>ump;
        for(int i=0;i<len;i++)
            ump[words[i]]++;
        for(auto x:ump)
        {
            if(sol(s,x.first))
                n+=x.second;
        }
        return n;
    }
};