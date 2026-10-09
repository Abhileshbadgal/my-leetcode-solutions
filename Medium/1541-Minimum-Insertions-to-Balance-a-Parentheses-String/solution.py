class Solution:
    def minInsertions(self, s: str) -> int:
        n = len(s)
        result = 0
        cnt = 0
        i = 0
        while i < n:
            if s[i] == '(':
                cnt += 1
                i += 1
            else:
                if cnt > 0:
                    cnt -= 1
                else:
                    result += 1
                if i + 1 < n and s[i + 1] == ')':
                    i += 2
                else:
                    result += 1
                    i += 1
        if cnt > 0:
            result += (2 * cnt)
        return result
