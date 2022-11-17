class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        
        int alength=abs(ax2-ax1);
        int awidth=abs(ay2-ay1);
        int blength=abs(bx2-bx1);
        int bwidth=abs(by2-by1);
        int areaa=alength*awidth;
        int areab=blength*bwidth;
        int ans=areaa+areab, rem=0;
        
        
        if((ax2<=bx1) || (ax1>=bx2) || ay1>=by2 || by1>=ay2 ) rem=0;
       
        
        else {
            
            rem=(min(ax2,bx2)-max(ax1,bx1))*(min(ay2,by2)-max(ay1,by1));
        } 
        
        return areaa+areab-rem;
        
        
    }
};