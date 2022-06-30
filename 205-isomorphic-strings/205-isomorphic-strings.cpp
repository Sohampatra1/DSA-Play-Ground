class Solution {
public:
    bool isIsomorphic(string s, string t) {
      int sind[129] = {0}, tind[129] = {0};                 //hash tables for characters from our strings
      
      for(int i = 0; i < s.size(); i++){
        if( sind[s[i]] != tind[t[i]] ) return false;        //if previous characters have different position
        sind[s[i]] = tind[t[i]] = i+1;                       //put last position of characters
      }
      
      return true;
    }
};