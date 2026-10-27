class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> result(m,string(n,'#'));
        for(int i = 0; i < m; i++){
            if(i == 0){
                result[0] = string(n,'.');
            }
            else{
                result[i][n-1] = '.';
            }
        }
        return result;
    }
};
