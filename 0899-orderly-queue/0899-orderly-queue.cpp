class Solution {
public:
    string orderlyQueue(string s, int k) {
        int n = s.size();
        
        if(k >= 2) sort(s.begin() , s.end());
    
        else {
            string lstr = s+s;
            for(int i=0 ; i<n ; i++){
                s = min(lstr.substr(i , n) , s);
            }
        }
        return s;
    }
};