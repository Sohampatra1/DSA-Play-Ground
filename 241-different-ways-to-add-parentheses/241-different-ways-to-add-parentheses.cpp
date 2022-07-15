class Solution {
public:
    
    bool isNumber(const string& str)
    {
        for (char const &c : str) {
            if (std::isdigit(c) == 0) return false;
        }
        return true;
    }
    map<pair<int,int>,vector<int>> mp;
    vector<int> rec(string s,int i,int j)
    {
        if(i == j || i+1 == j){
            return {stoi(s.substr(i,j+1-i))};
        }
        if(mp[{i,j}].size() != 0){
            return mp[{i,j}];
        }
        vector<int> ans;
        int k = i+1;
        while(k<j){
            if(!isdigit(s[k]))
            {
                vector<int> a = rec(s,i,k-1),b = rec(s,k+1,j);
                for(auto x:a){
                    for(auto y:b){
                        switch(s[k]){
                            case '+':
                                ans.push_back(x+y);
                                break;
                            case '-':
                                ans.push_back(x-y);
                                break;
                            case '*':
                                ans.push_back(x*y);
                                break;
                        }
                    }
                }
                
            }
            k++;
        }
        return mp[{i,j}] = ans;
    }
    vector<int> diffWaysToCompute(string s) {
        return rec(s,0,s.size()-1);
    }
};