class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int cnt = 0;
        int result = 0;
        int i = 0;
        while(i < n){
            if( s[i] == '('){
                cnt++;
                i++;
            }
            else{
                if(cnt > 0){
                    cnt--;
                }
                else result++;
                if(s[i + 1] == ')'){
                    i += 2;
                }
                else{
                    result++;
                    i++;
                }
            }
        }
        if( cnt > 0) result += (2*cnt);
        return result;
    }
};
