class Solution:
    def checkValidString(self, s: str) -> bool:
        dp=[[-1]*101 for _ in range(101)]
        def solve(s,ct,i):
            if i == len(s):
                if ct == 0:
                    return 1
                else:
                    return 0
            if ct < 0:
                return 0
            if dp[ct][i] != -1:
                return dp[ct][i]
            if s[i] == '(':
                dp[ct][i] = solve(s,ct + 1,i + 1)
            elif s[i] == ')' and ct == 0:
                return 0
            elif s[i] == ')':
                dp[ct][i] = solve(s,ct - 1,i + 1)
            else:
                dp[ct][i] = (
                    solve(s,ct + 1,i + 1) or
                    solve(s,ct,i + 1) or
                    (ct > 0 and solve(s,ct - 1,i + 1))
                )
            return dp[ct][i]
        return bool(solve(s,0,0))

