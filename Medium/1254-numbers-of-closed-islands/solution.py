class Solution:
    def closedIsland(self, grid: list[list[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        cnt = 0
        def dfs(grid, r, c):
            if r < 0 or r >= m or c < 0 or c >=n:
                return False
            if grid[r][c] == 1:
                return True
            grid[r][c] = 1
            left  = dfs(grid, r, c - 1)
            right = dfs(grid, r, c + 1)
            up    = dfs(grid, r - 1, c)
            down  = dfs(grid, r + 1, c)
            return left and right and up and down
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0:
                    if dfs(grid, i, j):
                        cnt += 1
        return cnt
        
