class Solution {
public:
    int romanToInt(string s) {
        int res=0;
		
        for(int i=0;i<s.size();i++){
            if(s[i]=='I'){
                if(s[i+1]=='V'){
                    res+=4;
                    i++;
                }
                else if(s[i+1]=='X'){
                    res+=9;
                    i++;
                }
                else if(s[i+1]=='L'){
                    res+=49;
                    i++;
                }
                else if(s[i+1]=='C'){
                    res+=99;
                    i++;
                }
                else if(s[i+1]=='D'){
                    res+=499;
                    i++;
                }
                else if(s[i+1]=='M'){
                    res+=999;
                    i++;
                }
                else{
                    res+=1;
                }
            }
            else if(s[i]=='V'){
                if(s[i+1]=='X'){
                    res+=5;
                    i++;
                }
                else if(s[i+1]=='L'){
                    res+=45;
                    i++;
                }
                else if(s[i+1]=='C'){
                    res+=95;
                    i++;
                }
                else if(s[i+1]=='D'){
                    res+=499;
                    i++;
                }
                else if(s[i+1]=='M'){
                    res+=995;
                    i++;
                }
                else{
                    res+=5;
                }
            }
            else if(s[i]=='X'){
                if(s[i+1]=='L'){
                    res+=40;
                    i++;
                }
                else if(s[i+1]=='C'){
                    res+=90;
                    i++;
                }
                else if(s[i+1]=='D'){
                    res+=490;
                    i++;
                }
                else if(s[i+1]=='M'){
                    res+=990;
                    i++;
                }
                else{
                    res+=10;
                }
            }
            else if(s[i]=='L'){
                if(s[i+1]=='C'){
                    res+=50;
                    i++;
                }
                else if(s[i+1]=='D'){
                    res+=450;
                    i++;
                }
                else if(s[i+1]=='M'){
                    res+=950;
                    i++;
                }
                else{
                    res+=50;
                }
            }
            else if(s[i]=='C'){
                if(s[i+1]=='D'){
                    res+=400;
                    i++;
                }
                else if(s[i+1]=='M'){
                    res+=900;
                    i++;
                }
                else{
                    res+=100;
                }
            }
            else if(s[i]=='D'){
                if(s[i+1]=='M'){
                    res+=500;
                    i++;
                }
                else{
                    res+=500;
                }
            }
            else if(s[i]=='M'){
                res+=1000;
            }
        }
        return res;
    }
};