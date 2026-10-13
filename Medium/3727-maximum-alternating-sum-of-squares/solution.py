class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        n = len(nums)
        half = n // 2
        for i in range(n):
            if nums[i] < 0:
                nums[i] = -1 * nums[i]
        nums.sort()
        a = 0
        b = 0
        for i in range(n):
            if i < half:
                b += (nums[i] * nums[i])
            else:
                a += (nums[i] * nums[i])
        return (a - b)
