class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        n = len(nums)
        mp = {}
        temp = nums.copy()
        def digitsum(num):
            sum = 0
            while num:
                sum += num % 10
                num //= 10
            return sum
        temp.sort(key = lambda num: (digitsum(num),num))
        for i in range(n):
            mp[nums[i]] = i
        swap = 0
        for i in range(n):
            curr = nums[i]
            exp  = temp[i]
            if curr == exp:
                continue
            idx = mp[exp]
            nums[i] = exp
            nums[idx] = curr
            mp[exp] = i
            mp[curr] = idx
            swap += 1
        return swap
            

        
