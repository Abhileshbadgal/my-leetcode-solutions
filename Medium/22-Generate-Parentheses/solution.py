class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        result = []
        def solve(curr,n,open,close):
            if(len(curr) == 2*n):
                result.append(curr)
            if(open<n):
                solve(curr + '(', n, open + 1, close)
            if(close < open):
                solve(curr + ')', n, open, close + 1)
        solve("",n,0,0)
        return result

        
