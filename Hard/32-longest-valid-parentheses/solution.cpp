class Solution {
public:
    int longestValidParentheses(string s) {
        int  n= s.size();
        int open = 0;
        int close = 0;
        int result = 0;
        //left to right
        for(auto& ch:s){
            if(ch == '('){
                open++;
            }
            else close++;
            if(open == close){
                result = max(result,open+close);
            }
            if(close > open){
                open = 0;
                close = 0;
            }
        }
        open = 0;
        close = 0;
        //right to left
        for(int i=n-1;i>=0;i--){
            if(s[i] == ')'){
                close++;
            }
            else open++;
            if(open == close){
                result = max(result,open+close);
            }
            if(close < open){
                open = 0;
                close = 0;
            }
        }
        return result;

    }
};
