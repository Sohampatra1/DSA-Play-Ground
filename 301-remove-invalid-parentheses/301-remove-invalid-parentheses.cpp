class Solution {
public:

    void dfs(string a,string s,int i,int ob,int cb,int o,unordered_set<string>&ans){
        
        if(i==s.size()){
            if(ob==0&&cb==0&&o==0){
            ans.insert(a);}
            return;
            }
        if(s[i]=='('){
            if(ob>0){
            dfs(a,s,i+1,ob-1,cb,o,ans);}
            dfs(a+s[i],s,i+1,ob,cb,o+1,ans);
        }
        else if(s[i]==')'){
            if(cb>0){
                dfs(a,s,i+1,ob,cb-1,o,ans);}
            if(o>0){
            dfs(a+s[i],s,i+1,ob,cb,o-1,ans);}
        }else{
            dfs(a+s[i],s,i+1,ob,cb,o,ans);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int ob=0;
        int cb=0;
        int l1=0;
        int l2=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                ob++;
                l1++;
            }else if(s[i]==')'){
                if(ob>0){
                    ob--;
                }else{
                    cb++;
                }
                l2++;
            }
        }
        string w="";
        if(l1==0){
            for(int i=0;i<s.size();i++){
                if(s[i]!=')'){
                    w+=s[i];
                }
            }
            vector<string> z;
            z.push_back(w);
            return z;
        }else if(l2==0){
            for(int i=0;i<s.size();i++){
                if(s[i]!='('){
                    w+=s[i];
                }
            }
            vector<string> z;
            z.push_back(w);
            return z;
        }
        
        unordered_set<string> ans;
        dfs("",s,0,ob,cb,0,ans);
        
        
        return vector<string>(ans.begin(),ans.end());
    }
};