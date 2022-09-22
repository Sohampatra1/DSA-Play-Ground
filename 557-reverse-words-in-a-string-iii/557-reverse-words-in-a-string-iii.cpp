class Solution {
public:
    string reverseWords(string s) 
    {
        int lb=0,ub;
        for(int i=0;i<s.size();i++)
        {
            ub=i;
            
            if(i==s.size()-1 || s[i+1]==' ')
            {
                while(lb<=ub)
                {
                    swap(s[lb],s[ub]);
                    lb++;
                    ub--;
                }
                lb=i+2;
            }
        }
        return s;
    }
};