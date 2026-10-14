class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string s = "";
        while( sum >= 9){
            s += '9';
            sum -= 9;
        }
        while(sum){
            s += ('0' + sum);
            sum = 0;
        }
        if(s.size() > num) return "";
        while(s.size() < num) s += '0';
        return s;
    }
};
