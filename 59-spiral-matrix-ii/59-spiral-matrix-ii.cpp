class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int l=0, r = n-1, t = 0, d = n-1;
        int count = 0;
        int temp = 1;
		
        vector<vector<int>> res(n,vector<int>(n,0));
        while(t<=d && l<=r){
            if(count == 0){
                vector<int> v;
                for(int i=l;i<=r;i++){
					//update the value
                    res[t][i] = temp;
                    temp++;
                }
                t++;
                count++;
                
            }
            else if(count == 1){
                vector<int> v;
                for(int i=t;i<=d;i++){
                   res[i][r] = temp;
                    temp++;
                }
                r--;
                count++;
                
            }
            else if(count == 2){
                vector<int> v;
                for(int i=r ;i>=l;i--){
                    res[d][i] = temp;
                    temp++;
                }
                d--;
                count++;
            }
            else if(count == 3){
                vector<int> v;
                for(int i=d;i>=t;i--){
                    res[i][l] = temp;
                    temp++;
                }
                l++;
                count = 0;
            }
        }
        return res;
    }
};