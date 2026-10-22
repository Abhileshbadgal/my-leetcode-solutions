class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        asc_cnt  = 0
        desc_cnt = 0
        for i in range(1,n):
            asc_cnt  += (nums[i] == (nums[i - 1] + 1) % n)
            desc_cnt += (nums[i - 1] == (nums[i] + 1) % n)
        if asc_cnt == n - 1 and nums[0] == 0:
            return 0
        # 2 3 4 5 6 7 0 1 
        if asc_cnt == n - 1:
            right = 1 + (nums[-1] + 1) + 1
            left  = n - nums[0]
            return min(right,left)
        # 4 3 2 1 0 7 6 5 
        if desc_cnt == n - 1:
            right = (nums[0] + 1) % n + 1
            left  = n - nums[-1] + 1
            return min(right, left)
        return -1
