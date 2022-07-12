class Solution {
public:
    int nucToInt (char c) {
        return c == 'G' ? 2 : c == 'T' ? 3 : c != 'A';
    }
    string intToDNA(int intDNA) {
        string res = "";
        int currNuc;
        while (res.size() < 10) {
            currNuc = intDNA % 4;
            res += currNuc == 3 ? 'T' : currNuc == 2 ? 'G' : currNuc ? 'C' : 'A';
            intDNA >>= 2;
        }
        return res;
    }
    vector<string> findRepeatedDnaSequences(string s) {
        int len = s.size();
        if (len < 10) return {};
     
        unordered_set<uint32_t> seen, written;
        uint32_t intDNA = 0;
        vector<string> res;
        
        for (int i = 0; i < 10; i++) {
            intDNA >>= 2;
            intDNA += nucToInt(s[i]) << 18;
        }
        seen.insert(intDNA);
        for (int i = 10; i < len; i++) {
          
            intDNA >>= 2;
            intDNA += nucToInt(s[i]) << 18;
           
            if (written.find(intDNA) == end(written)) {
              
                if (seen.find(intDNA) == end(seen)) seen.insert(intDNA);
               
                
                
                else {
                    res.push_back(intToDNA(intDNA));
                    written.insert(intDNA);
                }
            }
        }
        return res;
    }
};