class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i < n;i++){
            if(nums[i]<0) nums[i] = -1 * nums[i];
        }
        sort(nums.begin(),nums.end());
        long long b = 0;
        long long a = 0;
        int half = n/2;
        for(int i = 0 ;i < half; i++){
            b = b + (nums[i] * nums[i]);
        }
        for( int i= half; i< n;i++){
            a = a + (nums[i] * nums [i]);
        }
        return (a - b);
    }
};
