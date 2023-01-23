class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int>m1,m2;
              int m=trust.size();
          if(n==1&&m==0){
            return 1;
            }
        for(int i=0;i<m;i++){
              m1[trust[i][1]]++;
            m2[trust[i][0]]++;
        }
        int ans=0;
        for( auto x:m1){
                 if(x.second==n-1){
                ans=x.first;
               }
        }
        if(ans==0){
            return -1;
            }
        if(m2[ans]==0){
              return ans;
                     }
             return -1;
       }
};