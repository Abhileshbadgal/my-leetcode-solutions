class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int result = 0;
        while(i < n/2){
            if(n % (i+1) == 0) result += (nums[i] * nums[i]);
            i++;
        }
        result += (nums[n-1] * nums[n-1]);
        return result;
    }
};
