class Solution:
    def numOfWays(self, nums: list[int]) -> int:
        M = 10**9 + 7
        n = len(nums)
        PT = [[1] * (i + 1) for i in range(n)]
        for i in range(2, n):
            for j in range(1, i):
                PT[i][j] = (PT[i - 1][j - 1] + PT[i - 1] [j]) % M
        def solve(nums):
            n = len(nums)
            if n < 3:
                return 1
            root = nums[0]
            left  = [x for x in nums[1:] if x < root]
            right = [x for x in nums[1:] if x > root]
            x = solve(left) % M
            y = solve(right) % M
            z = PT[n - 1][len(left)] % M
            return (x * y * z) % M
        ans = solve(nums) % M
        return ans - 1

