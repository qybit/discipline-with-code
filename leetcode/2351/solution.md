题目链接：[2351. 第一个出现两次的字母](https://leetcode.cn/problems/first-letter-to-appear-twice/)

## 哈希表

利用哈希表存储字符串中全部字符的出现次数，当我们遍历字符串中第一次遇到已经存在的字符时，即可返回答案。

Code

```c++
class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char, int> m;
        for (char& c : s) {
            if (m.count(c) == 1) {
                return c;
            }
            m[c]++;
        }
        return ' ';
    }
};
```

### 复杂度分析

时间复杂度：$O(n)$，其中 $n$ 为字符串的长度，我们最多只会遍历一次字符串。

空间复杂度：$O(n)$，哈希表存储字符空间。