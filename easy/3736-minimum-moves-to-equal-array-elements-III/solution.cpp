class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx = *max_element(begin(nums), end(nums));
        int moves = 0;
        for(int x: nums) moves += (abs(mx - x));
        return moves;
    }
};
