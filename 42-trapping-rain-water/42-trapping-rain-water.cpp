class Solution {
public:
    int trap(vector<int>& ht) {
        int sum = 0;
        int l = 0;
        int r = ht.size()-1;
        while(l<r){
            if(ht[l]<=ht[r]){
                int curr = l;
                while(ht[++l] < ht[curr])
					sum += ht[curr] - ht[l];
            }
            else{
                int curr = r;
                while(ht[--r] < ht[curr])
					sum += ht[curr] - ht[r];
            }
        }
        return sum;
    }
};