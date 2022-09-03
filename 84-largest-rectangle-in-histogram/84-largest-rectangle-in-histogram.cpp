class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n,-1),right(n,n);
        stack<int> s;

		for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()-1] >= heights[i]){
                s.pop();
            }
            if(s.empty())
                left[i] = 0;
            else
                left[i] = s.top();
            s.push(i+1);
        }
         while(!s.empty())
             s.pop();

        for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            if(s.empty())
                right[i] = n;
            else
                right[i] = s.top();
            s.push(i);
        }
        int res = 0;
        for(int i=0;i<n;i++){
            res = max(res,(right[i]-left[i])*heights[i]);
        }
        return res;
    }
};