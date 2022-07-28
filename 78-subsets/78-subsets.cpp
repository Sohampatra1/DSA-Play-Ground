class Solution {
public:
    void rec(vector<int> &s,vector<vector<int>> &ss,vector<int> &a,int ii){
        ss.push_back(s);
        int i;
        for(i=ii;i<a.size();i++){
               s.push_back(a[i]);
             rec(s,ss,a,i+1);
            s.pop_back();
        }
         
        return;
    }
    
    vector<vector<int>> subsets(vector<int>& n) {
     
        
      vector<int> s;
        vector<vector<int>> ss;
         rec(s,ss,n,0);
        return ss;
    }
};