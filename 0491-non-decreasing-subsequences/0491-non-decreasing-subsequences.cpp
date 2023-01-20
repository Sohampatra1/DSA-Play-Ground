class Solution {
public:
    void cal(set<vector<int>>& freq,vector<int>& track,vector<int>& nums,int idx){
        if(idx>=nums.size()){
            if(track.size()>=2){
                freq.insert(track);
            }
             return; }
       int size = track.size();
          int value = INT_MIN;
        if(size >= 1) value = track[size-1];

        if(nums[idx]>=value){
            track.push_back(nums[idx]);
              cal(freq,track,nums,idx+1);
            track.pop_back();
        }
   cal(freq,track,nums,idx+1);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
            set<vector<int>> freq;
         vector<int> track;
          cal(freq,track,nums,0);
        vector<vector<int>> result;
        for(auto val:freq){
            result.push_back(val);
        }
          return result;
    }
};