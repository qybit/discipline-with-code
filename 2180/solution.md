题目链接：[2180. 统计各位数字之和为偶数的整数个数](https://leetcode.cn/problems/count-integers-with-even-digit-sum/)

## 模拟

题目数据量很小，直接按照题意模拟即可。

Code

```c++
class Solution {
public:
    int countEven(int num) {
        int ans = 0;
        for (int x = 1; x <= num; x ++) {
            int s = cal(x);
            if ((s & 1) == 0)  ans ++;  
        }
        return ans;
    }

    int cal(int x) {
        int s = 0;
        while (x  != 0) {
            s += x % 10;
            x /= 10;
        }
        return s;
    }
};
```

### 复杂度分析

时间复杂度：$O(nlogn)$，我们需要枚举 $n$ 个正整数，并且计算每个正整数各个位的和 $O(logn)$，因此时间复杂度为 $O(nlogn)$。

空间复杂度：$O(1)$。