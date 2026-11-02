class Solution:
    def minMoves2(self, nums: list[int]) -> int:
        nums.sort()
        median = nums[len(nums) // 2]
        moves = 0
        print(median)
        for x in nums:
            moves = moves + (abs(median - x))
        return moves
