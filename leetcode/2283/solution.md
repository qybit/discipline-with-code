题目链接：[2283. 判断一个数的数字计数是否等于数位的值](https://leetcode.cn/problems/check-if-number-has-equal-digit-count-and-digit-value/)

## 哈希表

根据题意，对于每一个下标 $i$ ，都需要满足 $i = count(nums[i])$，任意一个下标不满足即返回 $false$ 。对于统计 $nums[i]$ 的出现次数，直观上可以直接遍历字符串来计数统计即可。这里可以提前利用哈希表统计出字符串中所有字符的出现次数来进行小优化，因为数据量也不大。

Code

```c++
class Solution {
public:
    bool digitCount(string num) {
        int ans = 0;
        int n = num.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; i ++) {
            m[num[i] - '0'] ++;
        }
        for (int i = 0; i < n; i++) {
            int count = m[i], x = num[i] - '0';
            if (count != x) return false;
        }
        return true;
    }
};
```

### 复杂度分析

时间复杂度：$O(nlogn)$，其中 $n$ 为字符串 $num$ 的长度，我们枚举所有的下标，并查找该下标在字符串 $num$ 中的出现次数 $O(logn)$。因此时间复杂度为 $O(nlogn)$。

空间复杂度：$O(n)$。字符串 $num$ 中的每个数都是唯一的，此时哈希表长度为 $O(n)$ 。