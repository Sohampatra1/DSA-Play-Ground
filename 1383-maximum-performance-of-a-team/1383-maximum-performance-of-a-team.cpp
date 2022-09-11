class Solution {
private:
    #define F first
    #define S second
    const int mod = 1e9+7;
public:
    int maxPerformance(int n, vector<int>& sp, vector<int>& eff, int k) {
        long long ans = 0, sum = 0;
        vector<pair<int,int>> vp;
        
        for(int i=0; i<n; ++i) vp.push_back({eff[i], sp[i]});
        
        sort(rbegin(vp), rend(vp));
        
        priority_queue<int> pq;
       
        
        for(int i=0; i<n; ++i) {
            sum += vp[i].S;
            pq.push(-vp[i].S);
            
            if(pq.size() > k) {
                sum -= (-pq.top());
                pq.pop();
            }
            
            ans = max(ans, (sum * vp[i].F));
            
        }
        
        return ans%mod;
    }
};