class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        if(s.size()%2 ==1) return false;
        for(auto& ch:s){
            if(ch=='(' || ch=='{' || ch=='['){
                stk.push(ch);
            }
            else if(stk.empty()) return false;
            else if(ch==')' && stk.top()=='(') stk.pop();
            else if(ch==']' && stk.top()=='[') stk.pop();
            else if(ch=='}' && stk.top()=='{') stk.pop();
            else return false;
        }
        return stk.size()==0;
    }
};
