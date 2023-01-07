题目链接： [1658. 将 x 减到 0 的最小操作数](https://leetcode.cn/problems/minimum-operations-to-reduce-x-to-zero/)

## 滑动窗口

根据题意，可以对数组进行的操作有，删除一个数组前缀或删除一个数组后缀，最终修改完成的数组一定既删除了前缀又删除了后缀，也可能是删除其中一个的情况。那么剩下的数组一定是连续的子数组，且子数组的长度不确定，但是子数组的和是固定的。

设数组长度为 $n$，$l$ 和 $r$ 分别为剩下数组的左右边界，如果 $l =-1$ 表示前缀和为空，$r = n + 1$ 表示后缀和为空。前缀和和后缀和可以为空。

由于数组中的数均为正整数，当控制 $l$ 向右移动时（前缀和增加），$[l, r]$ 区间和也会增加，为了固定区间和大小，必须控制 $r$ 也向右移动 （后缀和减小），根据这一单调性可以使用滑动窗口来解决。

设 $l = -1$，$r = 0$ 初始化窗口大小，设 $lsum$ 表示前缀和大小，$rsum$ 表示后缀和大小，那么：

- $lsum + rsum = x$ ，表示我们找到了分别要删除的前缀和后缀，即确定了答案，此时的操作次数为 $(l + 1)+ (n - r)$；
- $lsum + rsum \gt x$ ，表示和过大，我们移动窗口右边界；
- $lsum + rsum \lt x$ ，表示和太小，我们移动窗口左边界；

Code

```c++
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        int n = nums.size();
        for (auto &x : nums) sum += x;
        if (sum < x) return -1;
        int lsum = 0, rsum = sum;
        int l = -1, r = 0;
        int ans = n + 1;
        while (l < n) {
            if (l != -1) {
                lsum += nums[l];
            }
            while (r < n && lsum + rsum > x) {
                rsum -= nums[r];
                r++;
            }

            if (lsum + rsum == x) {
                ans = min(ans, (l + 1) + (n - r));
            }
            l ++;
        }
        return ans > n ? -1 : ans;
    }
};
```

## 复杂度分析

时间复杂度：$O(N)$，其中 $N$ 表示为数组大小，$l$ 和 $r$ 均最多遍历一遍数组。

空间复杂度：$O(1)$ 。