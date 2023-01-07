题目链接：[1802. 有界数组中指定下标处的最大值](https://leetcode.cn/problems/maximum-value-at-a-given-index-in-a-bounded-array/)

## 暴力搜索

根据题意可以构造出一个符合以下约束的数组：

- `nums.length == n`
- `nums[i]` 是 正整数 ，其中 `0 <= i < n`
- `abs(nums[i] - nums[i+1]) <= 1` ，其中 `0 <= i < n-1`
- `nums` 中所有元素之和不超过 `maxSum`
- `nums[index]` 的值被 最大化

具体做法：

1. 对于下标 `index` ，枚举所有 `[1, maxSum]` 范围可能的值
2. `[0, index-1]` 范围内从 `1, ..., index-2, index-1` 递减，`[index+1, n]` 范围内从 `index-1,index-2, ... ,1` 递减
3. 最后再计算数组 $nums$ 的和即可。

Code：

```c++
typedef long long LL;

class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        for (int ret = maxSum; ret >= 1; ret --) {
            LL s = ret;
            for (int i = index-1; i>=0; i --) s += max(ret-index+i, 1);
            for (int i = index+1; i<n; i ++) s += max(ret-i+index, 1);
            if (s <= maxSum) return ret;
        }
        return -1;
    }
};
```

​	暴力算法很容易写，但是观察题目数据量为 $1 \le maxSum \le 10^9$，意味着 $N^2 = 10^{18}$ 次计算是不可能通过的。而且 $N$ 级时间复杂度也不足以通过，因此需要寻求对数复杂度。

​	观察约束3可知，下标 `index` 为数组中的最大值，`[0, index-1]` 为 `1` 递增到 `index-1`，`[index+1, n]` 为`index - 1`递减到 `1`。所以两边可以分别认为是 $d = 1$ 的等差数列。 `nums[index]` 取值一定满足$nums[index] \in [1, maxSum]$，且  $s$ 的大小与 $nums[index]$ 取值有关，$nums[index]$ 越大，$s$ 越大。因此可以使用二分搜索来确定 $nums[index]$ 的值。

### 复杂度分析

时间复杂度：$O(NC)$，其中 $N$ 为数组大小，$C$ 为常数，在本题中 $1 \le C \le 10^9$，我们枚举了 $C$ 次，并且每次都计算了数组的和 $O(N)$，因此时间复杂度为 $O(NC)$。

空间复杂度：$O(1)$。

## 二分搜索

​	解决了 $s$ 线性枚举的问题，还需要处理 $s$ 两侧的数组和。

​	设下标 $index$ 处为 $M$，考虑 $M$ 右侧，假设存在 $k$ 个数，第 $i$ 个数有 $max\{M - i, 1\}$，第 $k$ 个数有 $max\{M - k, 1\}$，计算 $M$ 右侧这 $k$ 个数的和，需要对 $k$ 进行分类讨论：

$M > k$ 时，此时第 $k$ 个数一定不为 `1`，所有 $k$ 的右侧不存在更多的 `1`，那么对于可以推导出 $a_1 = M - 1$，$a_k = M - k$，$n = k$，那么存在：
$$
S =  (\sum_{i=1}^{k}\{M -i\}) = \frac{k * (2M - 1 - k)}{2}
$$
$M \le k$ 时，此时第 $k$ 个数一定为 `1`，也就是说 $M$ 右侧从 $M - 1$ 开始一直递减到了 `1` ，且右侧还有 $k - M + 1$ 个 `1` ，可以推到出 $a_1=M - 1$，$a_{m-1} = 1$，$n=M-1$，那么存在：
$$
\begin{align}
S = &(\sum_{i=1}^{M-1}(M-i))+ k - M + 1 \\
  =	&\frac{M(M - 1)}{2} + k - M + 1 \\
  = &\frac{M(M - 3)}{2} + k + 1
\end{align}
$$
对 $M$ 左侧的 $k$ 个数也是同理。

Code：

```c++
typedef long long LL;

class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int leftCount = index, rightCount = n - 1 - index;
        int l = 1, r = maxSum;
        while (l <= r) {
            int m = (l + r) >> 1;
            LL sum = m + getSum(m, leftCount) + getSum(m, rightCount);
            if (sum > maxSum) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return l - 1;
    }

    LL getSum(int x, int k) {
        if (x > k) return (LL) k * (2 * x - 1 - k) / 2;
        return (LL)x * (x - 3) / 2 + k + 1 ;
    }
};
```

### 复杂度分析

时间复杂度： $O(logC)$，其中 $N$ 为数组大小，$C$ 为常数，在本题中 $1 \le C \le 10^9$ ，我们折半枚举了 $[1, C]$ 范围内的数，每次枚举都计算了数组的和 $O(1)$，因此时间复杂度为 $O(logC)$。

空间复杂度：$O(1)$。