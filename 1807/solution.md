题目链接：[1807. 替换字符串中的括号内容](https://leetcode.cn/problems/evaluate-the-bracket-pairs-of-a-string/)

## 哈希表

字符串 $s$ 中仅存在四种类型的字符：

- 字符 $($
- 字符 $)$
- 括号内的字符
- 括号外的字符

使用 $key$ 保存括号内的字符，$addkey$ 表示当前字符是否是属于括号内的字符，设 $ans$ 为答案字符串，那么遍历字符串 $s$ 中，对于字符 $c$ 有如下操作：

1. 当前字符为 $($，表示我们进入到了括号内；
2. 当前字符为 $)$，表示我们遍历了一个括号内的字符，此时在 $knowledge$ 中查找出 $key$ 是否存在（使用哈希表来优化查找过程），存在就将它加入到 $ans$ 中，否则将 $?$ 加入$ans$；
3. 对于括号内和括号外的字符，根据 $addkey$ 来判断加入 $key$ 字符串，还是答案字符串

Code

```c++
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> m;
        for (vector<string>& kv : knowledge) {
            m[kv[0]] = kv[1];
        }
        bool addKey = false;
        string ans, key;
        for (char c : s) {
            if (c == '(') {
                addKey = true;
            } else if (c == ')') {
                if (m.count(key) != 0) {
                    ans += m[key];
                } else {
                    ans.push_back('?');
                }
                addKey = false;
                key.clear();
            } else {
                if (addKey) {
                    key.push_back(c);
                } else {
                    ans.push_back(c);
                }
            }
        }
        return ans;
    }
};
```

### 复杂度分析

时间复杂度：$O(n + k)$，其中 $n$ 是字符串 $s$ 的长度，$k$ 是 $knowledge$ 数组中全部字符串的长度。

空间复杂度：$O(n+k)$。