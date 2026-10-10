class Solution:
    def minSumSquareDiff(self, nums1: list[int], nums2: list[int], k1: int, k2: int) -> int:
        countdiff = [0]*100001 
        k = k1 + k2
        minsum = 0
        for i in range(len(nums1)):
            b = abs(nums1[i] - nums2[i])
            countdiff[b] += 1
        for i in range(len(countdiff) - 1, 0, -1):
            if k > 0:
                countop = min(k,countdiff[i])
                countdiff[i] -= countop
                k -= countop
                countdiff[i - 1] += countop
        for i in range(1,len(countdiff)):
            minsum += countdiff[i] * i * i
        return minsum
