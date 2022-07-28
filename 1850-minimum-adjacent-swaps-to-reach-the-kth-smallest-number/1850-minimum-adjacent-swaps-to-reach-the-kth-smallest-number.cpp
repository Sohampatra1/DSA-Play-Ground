class Solution {
public:
  int getMinSwaps(string num, int k) {
    string s = num;
    int ans = 0;
    while(k--) next_permutation(s.begin(), s.end());
    
    
    for(int i = 0; i != s.size(); i++)
      if(s[i] != num[i]){
        int j = i + 1;
        while(s[j] != num[i]) j++;
        ans += j - i;
        while(j-- != i) swap(s[j], s[j+1]);
      }
    
    return ans;
  }
};