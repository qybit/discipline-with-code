题目链接：[695. 岛屿的最大面积](https://leetcode.cn/problems/max-area-of-island/)

## 深度优先搜索

二维矩阵中「岛屿」被定义为相邻的 $1$ 构成的组合，而岛屿的面积是值为 $1$ 的单元格的数目。这道题可以使用深度优先搜索，当找到某个值为 $1$ 的单元格时，搜索所有与其相邻的值为 $1$ 的单元格并修改其值为非 $1$ 值即可，每次修改就可以将面积大小加 $1$。

Code

```c++
class Solution {
public:

    int dirs4[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
    int m, n;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        this->m = m;
        this->n = n;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == 1) {
                    ans = max(ans, dfs(i, j, grid));
                }
            }
        }
        return ans;
    }

    int dfs(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1) return 0;
        grid[i][j] = -1;
        int res = 1;
        for (auto dir : dirs4) {
            int x = i + dir[0], y = j + dir[1];
            res += dfs(x, y, grid);
        }
        return res;
    }
};
```

### 复杂度分析

时间复杂度：$O(m \times n)$，其中 $m$ 是矩阵的行数，$n$ 是矩阵的列数。对于任意一个单元格，最多只会遍历一次。

空间复杂度：$O(m \times n)$，递归消耗的栈空间。

