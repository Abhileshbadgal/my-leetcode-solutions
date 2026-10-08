class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt=0;
        string result = "";
        int n = s.size();
        for(int i = 0; i < n;i++){
            if ( cnt ==0 && s[i] == '('){
                cnt++;   
            }
            else if(cnt== 1 && s[i] == ')'){
                cnt--;
            }
            else {
                if(s[i] == '('){
                    cnt++;
                    result += s[i];
                }
                else {
                    cnt--;
                    result += s[i];
                }
            }
        }
        return result;
    }
};
