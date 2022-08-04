class Solution {
public:
int mirrorReflection(int p, int q) {
int a=q; int b=p;
while(a){
if(b%a==0) break;
int temp=a;
a=b%a;
b=temp;
}

  int x= p/a;
    int y= q/a;
    
    if(x%2==1){
        if(y%2==1) return 1;
        else return 0;
    }
    else{
        if(y%2==1) return 2;
    }
    return 3;
}
};