class Solution:
    def numOfWays(self, nums: List[int]) -> int:
        mod = 10 ** 9 + 7
        
        def dfs(nums):
            if len(nums) < 3: return 1 

            root = nums[0] 

            l = [a for a in nums if a < root] 
            r = [a for a in nums if a > root] 

            return dfs(l) * dfs(r) * comb(len(nums) - 1, len(l)) % mod
        
        return (dfs(nums) - 1) % mod