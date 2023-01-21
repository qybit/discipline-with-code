题目链接：[1824. 最少侧跳次数](https://leetcode.cn/problems/minimum-sideway-jumps/)

## 动态规划

设 $dp[i][j]$ 为青蛙到达 $[i, j]$ 点时的最少跳跃次数，为了方便计算，我们规定跑道为 $0,1,2$ 号，在计算过程中取值 $obstacles[i] - 1$ 。

初始时，青蛙位于 $1$ 号跑道，那么 $dp[0][1] = 0$，表示没有障碍是可达的，其他的跑道则可以通过跳跃一次到达，即 $dp[0][1]=dp[0][2] = 1$，对于其他状态则用正无穷大 $inf$ 表示。

在转移过程中，考虑 

1.在前进过程中，青蛙可以从 $i - 1$ 跳到 $i$ 次，当 $i$ 处不存在障碍时即可到达，如果存在障碍就设为 $inf$。
$$
dp[i][j] = \left\{
\begin{aligned}
& dp[i-1][j]  & j \neq (obstacles[i] - 1) \\
& inf  & j = (obstacles[i] - 1)
\end{aligned}
\right.
$$
2.青蛙可以选择跳跃到另一个跑道，设 $count=min\{dp[i][0],dp[i][1],dp[i][2]\}$ 为 $3$ 条跑道中消耗跳跃次数最少的一条跑道。
$$
dp[i][j] = min \{count + 1, dp[i][j] \}
$$
其中 $j \in [0,2]$，且 $j \neq obstacles[i] - 1$。

经过 $n$ 次转移后，$min\{dp[n][j]\}, j \in [0,2]$ 就是答案。

在转移过程中，我们可以发现 $dp$ 数组只使用了 $dp[i-1]$ 来进行转移，这里可以利用滚动数组的思想来优化。

Code

C++

```c++
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> dp{1, 0, 1};
        const int inf = 1e9;
        for (int i = 0; i < n; i ++) {
            int count = inf;
            for (int j = 0; j < 3; j ++) {
                if (j == obstacles[i] - 1) {
                    dp[j] = inf;
                } else {
                    count = min(count, dp[j]);
                }
            }
            for (int j = 0; j < 3; j ++) {
                if (j == obstacles[i] - 1) {
                    continue;
                } else {
                    dp[j] = min(count + 1, dp[j]);
                }
            }
        }
        return *min_element(dp.begin(), dp.end());
    }
};
```

Swift

```swift
class Solution {
    func minSideJumps(_ obstacles: [Int]) -> Int {
        var n = obstacles.count
        var dp = [1, 0, 1]
        var inf = Int(1e9)
        for i in 0..<n {
            var count = inf
            for j in 0...2 {
                if j == obstacles[i] - 1 { 
                    dp[j] = inf
                } else {
                    count = min(count, dp[j])
                }
            }

            for j in 0...2 {
                if j == obstacles[i] - 1 {
                    continue
                }
                dp[j] = min(dp[j], count + 1)
            }
        }
        return dp.min()!
    }
}
```

### 复杂度分析

时间复杂度：$O(n)$，其中 $n$ 表示为数组 $obstacles$ 的长度。每次转移的时间为 $O(1)$，总共需要转移 $n$ 次，因此时间复杂度为 $O(n)$。

空间复杂度：$O(1)$，状态转移数组的长度为 $3$ 。