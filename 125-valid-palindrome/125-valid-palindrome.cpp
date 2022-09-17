class Solution {
public:
    bool isvalid(char ch)
    { if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9'))
            return 1;
                return 0;
    }
           char tolower(char ch)
{
    if((ch>='a'&&ch<='z')||(ch>='0'&&ch<='9'))
        return ch;
    else
    {
        char ans= ch-'A'+'a';
        return ans;}
}
    bool ispalindrome(string a)
        {
        int s=0;
        int e=a.length()-1;
        while(s<=e)
        {
            if(tolower(a[s])!=tolower(a[e]))
                return false;
              s++;e--;}
          return true;
    }
 bool isPalindrome(string s) {
        string ans= "";
          for(int i=0;i<s.length();i++)
        {
            if(isvalid(s[i]))
                ans.push_back(s[i]);}
        return ispalindrome(ans);
      }
};