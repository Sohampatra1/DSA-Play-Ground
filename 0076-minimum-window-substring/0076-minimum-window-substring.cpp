class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tMap, windowMap;
        
        for(int i=0; i<t.size(); i++)
            tMap[t[i]]++;
        
        int need = tMap.size(), have = 0, i = 0, j = 0, minLen = INT_MAX, first = 0;
        
        while(j < s.size()) {
            char ele = s[j];
            if(tMap.find(ele) == tMap.end()) {
                j++;
                continue;
            }        
            
            windowMap[ele]++;
            if(windowMap[ele] == tMap[ele])
                have++;
            
            while (have == need) {
                int len = j-i+1;
                if(len < minLen) {
                    minLen = len;
                    first = i;
                }
                    
                windowMap[s[i]]--;
                if( (tMap.find(s[i]) != tMap.end()) && (windowMap[s[i]] < tMap[s[i]]))
                    have--;
                
                i++;
            }
            
            j++;
        }
        
        return minLen == INT_MAX ? "" : s.substr(first, minLen);
    }
};