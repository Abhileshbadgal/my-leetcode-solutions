class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        result = ""
        cnt = 0
        for i in range(len(s)):
            if cnt == 0 and s[i] == '(':
                cnt += 1
            elif cnt == 1 and s[i] == ')':
                cnt -= 1
            else:
                if s[i] == '(':
                    result += s[i]
                    cnt += 1
                else:
                    result += s[i]
                    cnt -= 1
        return result
