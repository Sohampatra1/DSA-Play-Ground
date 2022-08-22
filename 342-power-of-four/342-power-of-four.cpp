class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1){
return true;
}
while(n!=0 && n%4==0){
if(n==4){
return true;
}
n=n/4;
}
return false;
    }
};

