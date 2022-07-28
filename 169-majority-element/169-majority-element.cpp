class Solution
{
    public:
    int majorityElement(vector<int>& nums)
    {
        map<int, int> frequency;
        int size = nums.size();
        int max = 0;
        int ret;
        for (int &i : nums)
        {
            frequency.insert(pair<int,int>(i, frequency[i]++));
            if (frequency[i] > max)
            {
                 max = frequency[i];
                 ret = i;
            }
        }
        return ret;
    }
};