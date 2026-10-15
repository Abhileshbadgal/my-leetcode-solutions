class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        ans = 0
        for i in range(len(nums)):
            st = set()
            for j in range(i,len(nums)):
                st.add(nums[j])
                ans += (len(st) * len(st))
        return ans
