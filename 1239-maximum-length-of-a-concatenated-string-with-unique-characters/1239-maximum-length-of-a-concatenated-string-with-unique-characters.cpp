class Solution {
public:

    int backtrack( int idx, vector<string> &arr, vector<int> &f ) {
        if( idx == arr.size() ) return 0;
        int npick = backtrack(idx+1, arr, f);
        bool flag = true;
        string s = arr[idx];
        
        for( int i = 0; i < s.size(); ++i ) {
            if( f[s[i]-'a'] != 0 ) flag = false;
            ++f[s[i]-'a'];
        }
        int pick = 0;
        if( flag )  pick = backtrack(idx+1, arr, f) + s.size();
        
        for( int i = 0; i < s.size(); ++i )
            --f[s[i]-'a'];
        return max(pick, npick);
    }
    
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        if( n == 0 ) return 0;
        vector<int> f(26, 0);
        return backtrack( 0, arr, f); 
    }
};