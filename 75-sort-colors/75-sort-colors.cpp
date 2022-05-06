class Solution
{
    public:
        void sortColors(vector<int> &nums)
        {

            int hi = nums.size() - 1;
            int mid = 0;
            int low = 0;

            while (mid <= hi)
            {

                switch (nums[mid])
                {
                    case 0:
                        swap(nums[mid++], nums[low++]);
                        break;
                    case 1:
                        mid++;
                        break;
                    case 2:
                        swap(nums[mid], nums[hi--]);
                        break;
                }
            }
        }
};