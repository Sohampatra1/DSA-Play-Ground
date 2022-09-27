
class Solution {
public:
    string pushDominoes(string s) {
        string ans=s;
        int siz=s.size();
        if(siz==1) return s;
        bool flag=false;
        queue<int> q;
        for(int i=0; i<siz; i++)
        {
            if(s[i]=='.') q.push(i);
            flag=true;
        }
        while(flag)
        {
            flag=false;
            while(!q.empty())
            {
                int f=q.front();
                if(f==siz-1 && s[siz-2]=='R') 
                {
                    ans[siz-1]='R';
                    flag=true;
                }
                
                if(f==0 && s[0]=='.'&&s[1]=='L') 
                {
                    ans[0]='L';
                    flag=true;
                }
                
                if(f!=0 && f!=siz-1 && s[f-1]=='R'&&s[f+1]!='L') 
                {
                    ans[f] = 'R';
                    flag=true;
                    
                }
                else if(f!=0 && f!=siz-1 && s[f-1]!='R' && s[f+1]=='L') 
                {
                    ans[f]='L';
                    flag=true;
                }
                
                q.pop();
            }
            s=ans;
            for(int i=0; i<siz; i++)
            {
                if(s[i]=='.') q.push(i);
            }
        }
        return ans;
    }
};