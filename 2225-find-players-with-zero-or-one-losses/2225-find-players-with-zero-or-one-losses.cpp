class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int , pair<int , int>> mp;
        vector<int> z , o;

        for(int i=0 ; i<matches.size() ; i++){
            int n = matches[i][0];
            int m = matches[i][1];
            mp[n].first++ ,mp[n].second++ ,mp[m].first++;
        }
        for(auto it:mp){
            int diff = (it.second.first)-(it.second.second);
            if(!diff) z.push_back(it.first);
            else if(diff == 1) o.push_back(it.first);   
        }
        return {z,o};
    }
};