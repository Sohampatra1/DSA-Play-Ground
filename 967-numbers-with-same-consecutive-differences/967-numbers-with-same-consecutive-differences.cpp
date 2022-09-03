class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        if(n==1)return {0,1,2,3,4,5,6,7,8,9};
        queue<int>q;
        for(int i=1;i<10;i++)q.push(i);
        int d=1;
        while(d<n){
            int temp=q.size();
            while(temp--){
                int top=q.front();
                q.pop();
                int last=top%10;
                if(last+k<10)q.push(top*10+last+k);
                if(k!=0 && last-k>=0 )q.push(top*10+last-k);
            }
            d++;
        }
        vector<int>out;
        while(q.size()){
            out.push_back(q.front());
            q.pop();
        }
        return out;
    }
};