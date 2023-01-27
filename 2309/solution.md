题目链接：[2309. 兼具大小写的最好英文字母](https://leetcode.cn/problems/greatest-english-letter-in-upper-and-lower-case/)

## 哈希表

根据题意返回大小写字母都在字符串中的大写字母。

直接将字符串存入哈希表中，按照字典序枚举所有的字母验证该字母的大小写是否都在哈希表中即可。

Code

```c++
class Solution {
public:
    string greatestLetter(string s) {
        unordered_set<char> m(s.begin(), s.end());
        for (int i = 25; i >= 0; i --) {
            if (m.count(i + 'A') > 0 && m.count(i + 'a') > 0) {
                return string(1, i + 'A');
            }
        }
        return "";
    }
};
```

### 复杂度分析

时间复杂度：$O(n + |\sum|)$，其中 $n$ 是字符串 $s$ 的长度，$|\sum|$ 表示字符集的大小，本题中 $|\sum| = 26$。

空间复杂度：$O(|\sum|)$，其中$|\sum|$ 表示字符集的大小，本题中 $|\sum| = 26$。

