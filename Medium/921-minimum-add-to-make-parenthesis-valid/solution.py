class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        cnt1 = 0
        cnt2 = 0
        for i in range(len(s)):
            if s[i] == '(':
                cnt1 += 1
            else:
                if cnt1 > 0:
                    cnt1 -= 1
        for i in range(len(s) - 1,-1,-1):
            if s[i] == ')':
                cnt2 += 1
            else:
                if cnt2 > 0:
                    cnt2 -= 1
        return cnt1 + cnt2

