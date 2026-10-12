class Solution:
    def maxSum(self, nums: List[int], k: int) -> int:
        result = 0
        M = 10**9 + 7
        count = [0] * 32
        for num in nums:
            for i in range(32):
                if num & (1 << i):
                    count[i] += 1
        while k > 0:
            curr = 0
            for i in range(32):
                if count[i] > 0:
                    count[i] -= 1
                    curr = curr | (1 << i)
            result = (result + curr * curr) % M
            k -= 1
        return int(result)

        
