class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        int i=0,sign=1;
        
        while(s[i]==' ') i++;

        if(s[i]=='-'){
            sign=-1;
            i++;
        }else if(s[i]=='+') ++i;
        
        while(s[i]>='0' && s[i]<='9'){
            ans = ans*10 + s[i++]-'0';
            if(ans > INT_MAX) return (sign == -1)? INT_MIN : INT_MAX;   
        }

        return sign*ans;
    }
};