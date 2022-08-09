class Solution {
public:
    int lengthOfLastWord(string s) {
        int c=0,flag=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==' ' && flag==1){
                break;
            }
            else if(s[i]!=' '){
                flag=1;
                c++;
            }
        }
        return c;
    }
};