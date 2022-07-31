class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int>pq;
        int distance=startFuel;
        int i=0,ans=0;
        
        while(distance < target){
            while(i < stations.size() && stations[i][0] <= distance){
                pq.push(stations[i++][1]);
            }
            if(pq.empty()) return -1;
            distance+=pq.top();
            pq.pop();
            ans++;
        }
        
        return ans;
    }
};