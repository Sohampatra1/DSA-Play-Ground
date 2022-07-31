class NumArray {
public:
    
    int n;
    vector<int>nums;
    int sum;
    NumArray(vector<int>& v) {
        n=v.size();
        nums = v;
        sum = accumulate(nums.begin(), nums.end(), 0);
    } 
    void update(int index, int val) {
        sum -= nums[index]; 
        nums[index] = val;
        sum += val;
        }
    int sumRange(int left, int right) {
        
        int ans = sum; 
        for(int i=0;i<left;i++){    
            ans -= nums[i];
        }
        for(int i=right+1;i<nums.size();i++){
            ans -= nums[i];
        }
        return ans;
    }
};