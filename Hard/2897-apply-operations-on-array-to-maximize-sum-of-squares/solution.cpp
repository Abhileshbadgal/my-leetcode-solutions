class Solution {
public:
    int MOD = 7 + 1e9;
    int maxSum(vector<int>& nums, int k) {
        vector<int> count(32,0);
        for( auto& num:nums){
            for(int i = 0;i < 32; i++){
                if( num & (1 << i)){
                    count[i]++;
                }
            }
        }
        int result = 0;
        while(k>0){
            long long curr = 0;
            for(int i = 0; i < 32; i++){
                if( count[i] > 0){
                    count[i]--;
                    curr = curr | (1 << i);
                }
            }
            result = (result + curr * curr) % MOD;
            k--;
        }
        return result; 
    }
};
