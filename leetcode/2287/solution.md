题目链接：[2287. 重排字符形成目标字符串](https://leetcode.cn/problems/rearrange-characters-to-make-target-string/)

## 哈希表

根据题意需要计算利用字符串 $s$ 中的字符，「最大」可以重组出多少个字符串 $target$ 。

由于只关注字符数量，而不关注字符出现顺序，所以可以利用哈希表来统计出字符串 $s$ 和 $target$ 中各字符出现的次数。假设对于 $target$ 中字符 $c$ 的出现次数为 $x$，$c$ 在字符串 $s$ 中的出现次数为 $y$，那么对于字符 $c$「最大」可以重组出 $\lfloor \frac{y}{x} \rfloor$ 次。如果 $y < x$ ，那么则不满足重组。

对于字符串 $target$ 中所有字符，遍历并计算出每个字符在字符串 $s$ 中的最大重组次数，并统计出所有字符中的最小重组次数，就是本题要求的在字符串 $s$ 中可以形成 $target$ 的「最大」副本数。

实际实现上，需要两个哈希表分别统计字符串 $s$ 和 $target$ 中字符出现次数，并且计算 $target$ 某个字符可以被 $s$ 重组的最大次数过程中，假如结果为 $0$ 表示 $target$ 不能被 $s$ 重组 ，我们可以提前返回答案。

Code

```c++
class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> m1, m2;
        for (char c : s) {
            m1[c] ++;
        }
        int ans = INT_MAX;
        for (char c : target) {
            m2[c] ++;
        }
        for (char c : target) {
            int t = m1[c] / m2[c];
            if (t == 0) return 0;
            ans = min(ans, t);
        }
        return ans;
    }
};
```

### 复杂度分析

时间复杂度：$O(m + n)$，其中 $m$ 为字符串 $s$ 的长度，$n$ 为字符串 $target$ 长度，我们分别遍历了字符串 $s$ 和 $target$ 统计次数，并且遍历了 $target$ 计算每个字符的最大重组次数。

空间复杂度：$O(m + n)$，存储两个字符串的哈希表空间。