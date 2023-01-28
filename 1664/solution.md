题目链接：[1664. 生成平衡数组的方案数](https://leetcode.cn/problems/ways-to-make-a-fair-array/)

## 前缀和

「平衡数组」定义为：选择一个下标并并删除对应的元素后，形成新的数组满足奇数下标之和与偶数下标之和相等的数组。现在选中一个下标 $0 \le i \lt n$ 进行删除操作，删除后的数组下标可能会发生变化。

设 $originalOdd$ 为数组前 $n$ 位奇数下标之和，$originalEven$ 为数组前 $n$ 位偶数下标之和。假设我们选择一个下标 $i$ 进行删除后，此时 $[0, i-1]$ 部分的下标奇偶性是不会变化的，而 $[i+1,n)$ 部分的下标则是奇偶反转。我们可以设 $leftOdd$ 为前 $i$ 项奇数下标之和，$leftEven$ 为前 $i$ 项偶数下标之和。对于删除一个下标后的数组奇偶下标之和就很容易在 $O(1)$ 时间获得。

当我们遍历到下标 $i$ 并选择删除时：

- $i$ 是奇数时：
    - $newOdd = originalOdd - leftOdd - nums[i] + leftEven$
    - $leftOdd \ += nums[i]$
- $i$ 是偶数时：
    - $newEven = originalEven - leftEven - nums[i] + leftOdd$
    - $leftEven \ += nums[i]$
- 当 $newOdd == newEven$ 时，表示删除当前下标 $i$ 后形成的数组可以构造成「平衡数组」。

Code

```c++
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        // 原始状态下奇偶之和
        int ori_odd = 0, ori_even = 0;
        for (int i = 0; i < n; i ++) {
            if (i & 1) {
                ori_odd += nums[i];
            } else {
                ori_even += nums[i];
            }
        }
        int res = 0;
        int left_odd = 0, left_even = 0;
        for (int i = 0; i < n; i ++) {
            int new_odd = ori_odd - left_odd - (i & 1 ? nums[i] : 0) + left_even;
            int new_even = ori_even - left_even - (i & 1 ? 0 : nums[i]) + left_odd;
            if (new_even == new_odd) res ++;
            i & 1 ? left_odd += nums[i] : left_even += nums[i];
        }
        return res;
    }
};
```

### 复杂度分析

时间复杂度：$O(n)$，其中 $n$ 是数组 $nums$ 的长度，我们最多遍历两次数组。

空间复杂度：$O(1)$。