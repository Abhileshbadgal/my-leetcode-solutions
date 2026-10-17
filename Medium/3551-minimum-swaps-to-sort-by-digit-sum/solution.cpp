class Solution {
public:
    int getdigitsum(int num){
        int sum = 0;
        while(num){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        vector<int> temp(nums.begin(), nums.end());
        auto lambda = [&](int num1, int num2){
            int num1digitsum = getdigitsum(num1);
            int num2digitsum = getdigitsum(num2);
            if( num1digitsum != num2digitsum){
                return num1digitsum < num2digitsum;
            }
            return num1 < num2;
        };
        sort(temp.begin(),temp.end(),lambda);
        for(int i = 0;i < n;i++){
            mp[nums[i]] = i;
        }
        int swap = 0;
        for(int i = 0;i < n;i++){
            int expected = temp[i];
            int curr = nums[i];
            if(expected == curr) continue;
            int idx = mp[expected];
            nums[i] = expected;
            nums[idx] = curr;
            mp[expected] =i;
            mp[curr] = idx;
            swap++;
        }
        return swap;
    }
};
