class Solution {
public:
    unordered_set<string> st;
    void solve(const string& s,int i,string& curr,int cnt, int& maxlen){
        if (cnt < 0) return;
        if(i == s.size()){
            if(cnt == 0){
                if(curr.length() > maxlen){
                    maxlen = curr.length();
                    st.clear();
                }
                if(curr.length() == maxlen){
                    st.insert(curr);
                }
            }
            return;
        }
        if (s[i] != '(' && s[i] != ')'){
            curr.push_back(s[i]);
            solve(s, i + 1,curr, cnt, maxlen);
            curr.pop_back();
            return;
        }
        curr.push_back(s[i]);
        solve(s, i + 1, curr, cnt + (s[i] == '(' ? 1 : -1), maxlen);
        curr.pop_back();
        solve(s, i + 1, curr, cnt, maxlen);
    }
    vector<string> removeInvalidParentheses(string s) {
        string curr="";
        int maxlen = 0;
        solve(s,0,curr,0, maxlen);
        vector<string> result(st.begin(), st.end());
        return result;
    }
};
