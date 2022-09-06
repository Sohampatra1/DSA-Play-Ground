class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res;
        int i = 0, j = 0;
        for(; i < m; i++){
            while(j < n && nums1[i] > nums2[j]){
                res.push_back(nums2[j]);
                j++;
            }
            res.push_back(nums1[i]);
        }
        
        while(j < n) {
            res.push_back(nums2[j]);
            j++;
        }
        
        for(int i = 0; i < res.size(); i++) nums1[i] = res[i]; 
    }
};