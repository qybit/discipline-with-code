题目链接：[967. 连续差相同的数字](https://leetcode.cn/problems/numbers-with-same-consecutive-differences/)

## 回溯

根据构造一个位数为 $n$ 相邻两位数字的差的绝对值为 $k$ 的数 $num$，我们可以借助回溯的思路来构造，定义 $pos$ 为当前位的数字，我们在枚举过程中存在：

- 当 $pos = 0$ 时，此时需要过滤掉 $0$ ，因为前导 $0$ 是不合法的，所以枚举第一个数需满足 $x(x \in [1,9])$ 。
- 当 $pos \gt 0 \ and \ pos \lt n $ 时，已知当前数 $num > 0$ ，那么再添加下一个时必须满足最后一个数与要添加的数 $x$ 的差的绝对值等于 $k$。即 $|(num \% 10 - x)| = k$ 。
- 当 $pos = n$ 时，表示已经找到了符合要求长度为 $n$ 的数，把它加入到答案即可。

在构造数 $num$ 时不必借助数组，用简单的数学计算即可。

- 添加一个数对应的操作：$num = num * 10 + x$
- 移除一个数对应的操作：$num = num / 10$

Code

```c++
class Solution {
public:

    vector<int> ans;
    int cur = 0;
    const int N = 9;
    int n, k;

    void backtrace(int pos) {
        if (pos >= n) {
            ans.emplace_back(cur);
            return;
        }
        for (int x = 0; x <= N; x ++) {
            if (pos == 0 && x == 0) continue; // 前导0
            if (cur > 0) {
                if (abs(x - (cur % 10)) != k) continue;
            }
            cur = cur * 10 + x;
            backtrace(pos + 1);
            cur /= 10;
        }
    }

    vector<int> numsSameConsecDiff(int _n, int _k) {
        n = _n, k = _k;
        backtrace(0);
        return ans;
    }
};
```

### 复杂度分析

时间复杂度：$O(2^N)$，其中 $N$ 是数的范围，本题中 $N = 9$。

空间复杂度：$O(2^N)$，递归栈空间的消耗。