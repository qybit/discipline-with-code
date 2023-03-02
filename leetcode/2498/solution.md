题目链接：[2498. 青蛙过河 II](https://leetcode.cn/problems/frog-jump-ii/)

## 贪心

青蛙跳跃石头从 $0$ 号位置跳到最后一个位置，又从最后一个位置跳回到 $0$ 号位置，并且每个石头最多只能到达一次。「最大跳跃长度」这里表示为青蛙跳跃过程中从 $stones[i]$ 跳到 $stones[j]$ 时，跳跃长度为 $|stones[i]-stones[j]|$ 。「最小代价」则表示为跳完全程后的最大跳跃高度的最小值。

假设存在严格递增的石子路径 $a \rightarrow b \rightarrow c \rightarrow d$，

- 不采用间隔跳，$a \rightarrow d \rightarrow c \rightarrow b \rightarrow a$
- 采用间隔跳，$a \rightarrow c \rightarrow d \rightarrow b \rightarrow a$

显然 $a \rightarrow d$ 是必然小于 $a \rightarrow c$ 和 $d \rightarrow b$ 的，因此间隔跳是最优解。

Code

```c++
class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        int ans = stones[1] - stones[0];
        for (int i = 2; i < n; i ++) {
            ans = max(ans, stones[i] - stones[i - 2]);
        }
        return ans;
    }
};
```

### 复杂度分析

时间复杂度：$O(n)$，其中 $n$ 是 $stones$ 的长度。

空间复杂度：$O(1)$。