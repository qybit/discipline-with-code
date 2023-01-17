题目链接：[1814. 统计一个数组中好对子的数目](https://leetcode.cn/problems/count-nice-pairs-in-an-array/)

## 哈希表

题目理解起来比较容易，遍历数组 $nums$ 分别找到两个下标对 $i, j(0 \le i \lt j)$，使得 $nums[i] + rev(sums[j]) == nums[j] + rev(nums[i])$、其中 $rev()$ 函数则表示反转数字大小。不难写出暴力算法，但是直接暴力查找会导致超时（数据量最大 $10^5$），那么可以考虑优化一下查找另一个下标的过程。

当我们确定一个 $i$ 时，存在 $f(i) = nums[i] - rev(nums[i])$，我们希望找到另外一个下标 $j (j \in [0,i-1])$ 使得 $f(i) = f(j)$，而满足这样的下标 $j$ 可能存在多个。那么我们借助哈希表存储 $f(x)$ 的个数，就可以实现一次遍历数组 $nums$ 获取到每个下标 $i$ ，对应的满足等式 $f(i) =f(j)$ 中下标 $j$ 的全部个数。

Code

```c++
class Solution {
public:
    
    int reverseNum(int x) {
        int a = 0;
        while (x != 0) {
            a = a * 10 + x % 10;
            x /= 10;
        }
        return a;
    }

    int countNicePairs(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int ans = 0, n = nums.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; i ++) {
            int x = nums[i], y = reverseNum(nums[i]);
            int f = x - y;
            ans = (ans + m[f]) % MOD;
            m[f] ++;
        }
        return ans;
    }
};
```

### 复杂度分析

时间复杂度：$O(n \times logC)$，其中 $n$ 为数组 $nums$ 的长度，我们遍历一次数组 $O(n)$，每次遍历一个下标 $i$，需要计算出 $f(i)$ 的值 $O(logC)$，$C$ 为常数本题中最大为 $10^9$。

空间复杂度：$O(n)$，哈希表需要存储每个下标 $f(i)$ 的值。