class Solution:
    def longestValidParentheses(self, s: str) -> int:
        open = 0
        close = 0
        result = 0
        for ch in s:
            if ch == '(':
                open += 1
            else:
                close +=1
            if open == close:
                result = max(result,open+close)
            elif close > open:
                open = 0
                close = 0
        open = 0
        close = 0
        for ch in reversed(s):
            if ch == ')':
                close += 1
            else:
                open += 1
            if open == close:
                result = max(result,open+close)
            elif open > close:
                open = 0
                close = 0

        return result
