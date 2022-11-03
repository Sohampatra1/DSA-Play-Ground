class Solution {
public:
    int longestPalindrome(vector<string>& words) {
          unordered_map <string, int> hash;
              int ans = 0;
                 int addOne = 0;
    for ( auto itr: words ) hash[itr]++;
        for ( auto itr: words){
            string str = itr;
               string rev = itr;
                  reverse(rev.begin(), rev.end());
            
            if ( str != rev && hash[rev]+hash[str] >= 2 ){
                 ans += min(hash[str], hash[rev])*4;
                   hash[rev] = 0, hash[str] = 0;
            }
            else if (str == rev && hash[str] != 0) {
                  ans += (hash[str]/2)*4;
                    if ( hash[str]%2 == 1 ) addOne = 1;
                        hash[str] = 0;
                 }
            }
            if ( addOne == 1 ) return ans+2;
                 else return ans;
                             }
                  };