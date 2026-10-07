class Solution:
    def removeInvalidParentheses(self, s: str) -> list[str]:
        curr = ""
        maxlen = [0]
        st = set()
        def solve(i, curr, cnt, maxlen):
            if cnt < 0:
                return
            if i == len(s):
                if cnt == 0:
                    if len(curr) > maxlen[0]:
                        maxlen[0] = len(curr);
                        st.clear();
                    if len(curr) == maxlen[0]:
                        st.add(curr);
                return
            if s[i] not in  "()":
                solve(i+1, curr + s[i], cnt, maxlen)
                return
            if s[i] == '(':
                solve(i + 1, curr + s[i], cnt + 1, maxlen)
            else:
                solve(i + 1, curr + s[i], cnt - 1, maxlen)
            solve(i + 1, curr, cnt, maxlen)
        solve(0, curr, 0, maxlen)
        return list(st)












                 



        
