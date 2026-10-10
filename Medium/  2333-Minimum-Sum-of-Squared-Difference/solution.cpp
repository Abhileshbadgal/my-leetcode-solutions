class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long minsum=0;
        vector<int> countdiff(1e5 + 1,0);
        for( int i = 0; i < nums1.size(); i++){
            int d = abs(nums1[i] - nums2[i]);
            countdiff[d]++;
        }
        int k = k1 + k2;
        for(int i = 1e5;i >= 1 && k > 0;i--){
            int countop = min(k,countdiff[i]);
            countdiff[i] -= countop;
            k -= countop;
            countdiff[i-1] += countop;
        }
        for( long long i = 1;i <= 1e5;i++){
            minsum += 1LL * (countdiff[i] * i * i);
        }
        return minsum;
    }
};
