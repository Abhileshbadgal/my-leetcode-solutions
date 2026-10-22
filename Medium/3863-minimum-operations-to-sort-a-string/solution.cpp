class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        if(is_sorted(begin(s), end(s))) return 0;
        if(s.length() == 2) return -1;
        char min_char = *min_element(begin(s), end(s));
        char max_char = *max_element(begin(s), end(s));
        if(min_char == s[0] || max_char == s[n-1]) return 1;
        char max_mid = *max_element(begin(s) + 1, end(s) - 1); 
        char min_mid = *min_element(begin(s) + 1, end(s) - 1);
        if(min_mid > s[n-1] && max_mid < s[0] ){
            return 3;
        }
        return 2;
    }
};
