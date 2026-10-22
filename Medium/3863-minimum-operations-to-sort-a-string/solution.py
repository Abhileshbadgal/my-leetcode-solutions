class Solution:
    def minOperations(self, s: str) -> int:
        n = len(s)
        temp = sorted(s)
        if s == "".join(temp):
            return 0
        if n == 2:
            return -1
        min_char = min(s)
        max_char = max(s)
        if min_char == s[0] or max_char == s[-1]:
            return 1
        mid = s[1: -1]
        min_mid = min(mid)
        max_mid = max(mid)
        if s[0] > max_mid and s[-1] < min_mid:
            return 3
        return 2

        
