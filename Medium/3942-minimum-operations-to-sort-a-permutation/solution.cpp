class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int asc_cnt = 0;
        int desc_cnt = 0;
        for(int i = 1; i < n; i++){
            desc_cnt += (nums[i - 1] == (nums[i] + 1) % n);
            asc_cnt  += (nums[i] == (nums[i - 1] + 1) % n);
        }
        if(asc_cnt == n - 1 && nums[0] == 0){
            return 0;
        }
        // 4 5 6 0 1 2 3
        if(asc_cnt == n-1){
            int  left = n - nums[0];
            int right = 1 + (nums.back() + 1) + 1 ;
            return min(left,right);
        }
        if(desc_cnt == n - 1){
            // reverse mendatory
           int  left = n - nums.back() + 1;
           int right = (nums[0] + 1) % n + 1;
           return min(left, right);
        }
        return -1;
    }
};
