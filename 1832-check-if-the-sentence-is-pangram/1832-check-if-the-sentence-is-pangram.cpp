class Solution {
public:
    bool checkIfPangram(string s) {
        bool a[26] = {0} ; 
        for(int i = 0 ; i < s.size() ; i++)
            a[s[i]-'a'] = 1 ; 
        for(int i = 0 ; i < 26 ; i++)
            if(!a[i])
                return false ; 
        return true ;
    }
};