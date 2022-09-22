class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int remain = 0;
        int index = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            remain += gas[i];
            if (remain < cost[i])
            {
                if (i >= index)
                {
                    index = i+1;
                }
                else
                {
                    break;
                }
                remain = 0;
                continue;
            }
            remain -= cost[i];
            if ((index == 0 && i == gas.size()-1) || (index != 0 && i == index-1))
            {
                return index;
            }
            if (i == gas.size()-1)
            {
                i = -1;
            }
        }
        return -1;
    }
};