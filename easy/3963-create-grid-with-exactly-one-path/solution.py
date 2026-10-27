class Solution:
    def createGrid(self, m: int, n: int) -> list[str]:
        result = [['#'] * n for _ in range(m)]
        result[0] = ['.'] * n
        for i in range(1,m):
            result[i][n-1] = '.'
        return ["".join(row) for row in result]
