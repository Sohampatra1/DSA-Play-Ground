class Solution {
public:
    int maximumGap(vector<int>& a) {
        int n=a.size(), maxi = INT_MIN, mini = INT_MAX, ans = INT_MIN;
        vector<vector<int>> bucket(n+1);
        for(int i=0;i<n;i++)
        {
            maxi = max(a[i], maxi);
            mini = min(a[i], mini);
        }
        if(maxi == mini)
            return 0;
        
        //create bucket
        int range = (maxi - mini)/n + 1; // range must be greater than equal to 1
        for(int i=0;i<n;i++)
        {
            
            int b_index = (a[i] - mini)/range;
            if((a[i]-mini)%range==0 && a[i]!=mini)
            {
                bucket[((a[i] - mini)/range) - 1].push_back(a[i]);
                continue;
            }
            bucket[b_index].push_back(a[i]);
        }
        
        // traverse bucket
        int temp = -1;
        for(auto p:bucket)
        {
            if(p.size()==0)
                continue;
            sort(p.begin(), p.end());
            for(int i=0;i<p.size();i++)
            {
                if(temp == -1)
                {
                    temp = p[i];
                    continue;
                }
                ans = max(ans, p[i]-temp);
                temp = p[i];
            }
        }
        return ans;
    }
};