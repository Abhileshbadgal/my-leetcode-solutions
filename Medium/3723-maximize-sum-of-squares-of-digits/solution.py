class Solution:
    def maxSumOfSquares(self, num: int, sum: int) -> str:
        s = ""
        while  sum >= 9:
            s += '9'
            sum -= 9
        while sum:
            s += str(sum)
            sum = 0
        if len(s) > num:
            return ""
        while len(s) < num:
            s += '0'
        return s
