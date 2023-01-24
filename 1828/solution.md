题目链接：[1828. 统计一个圆中点的数目](https://leetcode.cn/problems/queries-on-number-of-points-inside-a-circle/)

## 模拟

直接遍历查询数组 $queries$ ，再枚举全部的 $points$ 即可，定义：
$$
(x_i - x_j)^2 + (y_i - y_j) ^ 2 \le d ^2
$$
其中 $x_i, y_i$ 表示为 $queries[i]$ 中的一个查询，$d$ 表示查询半径，$x_j, y_j$ 表示 $points[j]$ 中的一个点。

任意一个点满足以上式子，即表示该点在查询的圆上。

由于数据都比较弱且平方后不会溢出，可以避免浮点数运算带来的误差。

Code

Cpp

```c++
class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans;
        for (auto &&q : queries) {
            int rx = q[0], ry = q[1], d = q[2];
            int count = 0;
            for (auto &&p : points) {
                int x = p[0], y = p[1];
                bool isIn = (rx - x) * (rx - x) + (ry - y) * (ry - y) <= d * d;
                if (isIn) {
                    count ++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};
```

Swift

```swift
class Solution {
    func countPoints(_ points: [[Int]], _ queries: [[Int]]) -> [Int] {
        var ans: [Int] = []
        var n = queries.count
        for q in queries {
            var rx = q[0], ry = q[1], d = q[2]
            var count = 0
            for p in points {
                var x = p[0], y = p[1]
                var isIn = (rx - x) * (rx - x) + (ry - y) * (ry - y) <= d * d
                if isIn {
                    count += 1
                }
            }
            ans.append(count)
        }
        return ans
    }
}

### 复杂度分析

时间复杂度：$O(n \times m)$，其中 $n$ 是数组 $queries$ 的长度，$m$ 是数组 $points$ 的长度。我们枚举全部的查询 $O(n)$，在每一个查询中枚举全部坐标 $O(m)$，计算坐标是否在圆上 $O(1)$。因此时间复杂度是 $O(n \times m)$ 。

空间复杂度：$O(n)$，其中 $n$ 是数组 $queries$ 的长度，我们计算完成后存储答案。