class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size();
        int open = 0;
        int cl = 0;
        stack<int> st1;
        stack<int> st2;
        for(int i = 0;i<n;i++){
            if(s[i] == '('){
                st1.push('(');
            }
            else if(!st1.empty()){
                st1.pop();
            }
        }
        for(int i=n-1;i>=0;i--){
            if(s[i] == ')'){
                st2.push(')');
            }
            else if(!st2.empty()){
                st2.pop();
            }
        }
        return st1.size() + st2.size();
        
    }
};
