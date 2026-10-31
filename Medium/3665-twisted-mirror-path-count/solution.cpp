class Solution {
public:
    int M = 1e9 + 7;
    int m, n;
    int left = 0;
    int up = 1;
    int solve(vector<vector<int>>& grid, int i, int j, int comefrom, vector<vector<vector<int>>>& t){
        if(i >= m || j >= n){
            return 0;
        }
        if(i == m - 1 && j == n - 1){
            return 1;
        }
        if(t[i][j][comefrom] != -1){
            return t[i][j][comefrom];
        }
        if(grid[i][j] == 1){
            if(comefrom == left){
                return t[i][j][comefrom] = solve(grid,i + 1, j, up, t);
            }
            else {
                return t[i][j][comefrom] = solve(grid, i, j + 1, left, t);
            }
        }
        int cnt = 0;
        cnt = (cnt + solve(grid, i, j + 1, left, t)) % M;
        cnt = (cnt +  solve(grid, i + 1, j, up, t)) % M;
        return t[i][j][comefrom] = cnt;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<vector<int>>> t(m + 1, vector<vector<int>>(n + 1, vector<int>(2, -1)));
        return solve(grid, 0, 0, 0, t);
    }
};
