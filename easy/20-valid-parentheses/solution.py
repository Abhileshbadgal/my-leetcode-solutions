class Solution:
    def isValid(self, s: str) -> bool:
        stk=[]
        if len(s) % 2 == 1:
            return False
        for ch in s:
            if ch in '[({':
                stk.append(ch)
            elif not stk:
                return False
            elif ch == ')' and stk[-1] == '(':
                stk.pop()
            elif ch == ']' and stk[-1] == '[':
                stk.pop()
            elif ch == '}' and stk[-1] == '{':
                stk.pop()
            else: 
                return False
        return len(stk) == 0

        
