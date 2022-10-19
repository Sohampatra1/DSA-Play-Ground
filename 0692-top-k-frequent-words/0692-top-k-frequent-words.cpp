class Solution {
public:
    bool static cmp(pair<string,int>a,pair<string,int>b)
    {
        if(a.second==b.second)
            return a.first<b.first;
        else
            return a.second>b.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        unordered_map<string,int>m;
        for(string it : words)
            m[it]++;
        vector<pair<string,int>>v;
        for(auto it:m)
            v.push_back({it.first,it.second});
        sort(v.begin(),v.end(),cmp);
        vector<string>ans;
        for(int i=0;i<k;i++)
            ans.push_back(v[i].first);
        return ans;
    }
};