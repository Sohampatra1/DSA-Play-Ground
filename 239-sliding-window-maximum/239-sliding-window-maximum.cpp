class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        // Find next greater element to the right of every element
        int * right = new int[nums.size()];
        stack<int> st;
        st.push(nums.size() - 1);
        right[nums.size()-1] = nums.size();
        
        for(int idx = nums.size() - 2; idx >= 0; idx--){
            while(st.size() > 0 && nums[idx] >= nums[st.top()])
                st.pop();
            
            if(st.size() == 0)
                right[idx] = nums.size();
            else
                right[idx] = st.top();
            
            st.push(idx);
        }
        
        // Now find next greater element in current window
        int jdx = 0;
        vector<int> ans;
        for(int idx = 0; idx <= nums.size() - k; idx ++){
            if(jdx < idx)
                jdx = idx;
            
            while(right[jdx] < idx + k)
                jdx = right[jdx];
            
            ans.push_back(nums[jdx]);
        }
        
        return ans;
    }
};