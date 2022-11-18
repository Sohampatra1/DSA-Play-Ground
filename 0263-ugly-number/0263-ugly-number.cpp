class Solution {
public:
    bool isUgly(int n) {
    bool t=true;
    bool ans=false;  
    if(n<=0){
        return false;
    }     
    while(t){
        if(n==1){
            ans=true;
            t=false;
            break;
        }
        if(n%2==0 || n%3==0 || n %5==0){
            if(n%2==0){
                n=n/2;
            }
            else if(n%3==0){
                n=n/3;
            }
            else{
                n=n/5;
            }
             }
        else{
            t=false;
            break;
        }
    }
    return ans;


    }
};