class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
       
        
        unordered_map <string, unordered_map <string, double>> mp;
        for(int i = 0; i<equations.size(); i++){
            double v = values[i];
            mp[equations[i][0]][equations[i][1]] = v;
            mp[equations[i][1]][equations[i][0]] = 1/v;
            mp[equations[i][0]][equations[i][0]] = 1.0;
            mp[equations[i][1]][equations[i][1]] = 1.0;
        }
        
        
        for(auto i: mp){
            for(auto j : mp[i.first]){
                for(auto k: mp[i.first])
                    mp[j.first][k.first] = mp[j.first][i.first] * mp[i.first][k.first];
            }
        }
        
        
        vector <double> v;
        for(auto i: queries){
            string from = i[0];
            string to = i[1];
            if((mp.find(from)!=mp.end()) && (mp[from].find(to)!=mp[from].end()))
                v.push_back(mp[from][to]);
            else
                v.push_back(-1.0);
        }
        
        return v;
    }
};