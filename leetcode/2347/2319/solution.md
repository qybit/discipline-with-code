题目链接：[2319. 判断矩阵是否是一个 X 矩阵](https://leetcode.cn/problems/check-if-matrix-is-x-matrix/)

## 枚举

根据题意 **X矩阵** 被定义为：

1. 矩阵对角线上的所有元素都 **不是 0**
2. 矩阵中所有其他元素都是 **0**

对角线上的元素位置满足 $i = j$ 或 $i + j + 1 = n$，当 $matrix[i][j] = 0$ 时表示对角线上的元素存在 **0** ，返回 $false$。其他位置若不为 **0** 时也返回 $false$。检查完整个二维数组后则返回 $true$。

Code

```c++
class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (i == j || i + j == n - 1) {
                    if (grid[i][j] == 0) return false;
                } else {
                    if (grid[i][j]) return false;
                }
            }
        }
        return true;
    }
};
```

### 复杂度分析

时间复杂度：$O(n^2)$，其中 $n$ 是正方形矩阵的行数和列数。

空间复杂度：$O(1)$。

