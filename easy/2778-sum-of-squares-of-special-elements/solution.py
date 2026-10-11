class Solution:
    def sumOfSquares(self, nums: List[int]) -> int:
        n = len(nums)
        result = 0
        i = 0
        while i < n//2:
            if n % (i + 1) == 0:
                result += (nums[i] * nums[i])
            i += 1
        result += nums[-1] * nums[-1]
        return result;
