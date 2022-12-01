class Solution {
public:
    bool halvesAreAlike(string r) {
        int count=0;
    int count1=0;
      
    for(int i=0;i<r.size()/2;i++){
    
         if(r[i]=='a'||r[i]=='e'||r[i]=='i'||r[i]=='o'||r[i]=='u'||r[i]=='A'||r[i]=='E'||r[i]=='I'||r[i]=='O'||r[i]=='U'){
count++;}

if(r[(r.size()/2)+i]=='a'||r[(r.size()/2)+i]=='e'||r[(r.size()/2)+i]=='i'||r[(r.size()/2)+i]=='o'||r[(r.size()/2)+i]=='u'||r[(r.size()/2)+i]=='A'||r[(r.size()/2)+i]=='E'||r[(r.size()/2)+i]=='I'||r[(r.size()/2)+i]=='O'||r[(r.size()/2)+i]=='U'){
count1++;}
    
        
    }
    
    
    
    
    if(count==count1){
        return true;
    }
    return false;
    }
};