/**
 * @param {number[][]} grid
 * @return {number[][]}
 */
var largestLocal = function(grid) {
    const n = grid.length
    const ans = new Array(n - 2).fill(0).map(_ => new Array(n - 2).fill(-1))
    const dirs = [[1, 1], [1, 0], [1, -1], [0, 1], [0, -1], [-1, 1], [-1, -1], [-1, 0]]
    for (let i = 1; i < n - 1; i ++) {
        for (let j = 1; j < n - 1; j ++) {
            let max = grid[i][j]
            for (const dir of dirs) {
                let x = dir[0] + i, y = dir[1] + j
                max = Math.max(max, grid[x][y])
            }
            ans[i - 1][j - 1] = max
        }
    }
    return ans
};