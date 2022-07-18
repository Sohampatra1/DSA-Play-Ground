class Solution {
public:

int numSubarraysWithSum(vector<int>& nums, int goal) 
{
    unordered_map<int,int>mp;
    int count=0,sum=0;
    mp[sum]=1;
    for(auto&x:nums)
    {
        sum+=x;
        count+=mp[sum-goal];
        //cout<<count;
        mp[sum]++;
    }
    return count;
}
};