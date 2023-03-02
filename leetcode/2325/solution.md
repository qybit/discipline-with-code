题目链接：[2325. 解密消息](https://leetcode.cn/problems/decode-the-message/)

## 模拟

根据题意设 $ch$ 表示为初始字母 `'a'` ，使用哈希表存储字符串 $key$ 中首次出现的字母，并把 $ch$ 表示为下一个字母。最后根据哈希表替换字符串 $message$。

Code

```c++
class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> m;
        int ch = 0;
        for (char c : key) {
            if (c == ' ' || m.count(c)) continue;
            m[c] = (char)(ch + 'a');
            ch ++;
        }
        for (char& c : message) {
            if (c == ' ') {
                continue;
            }
            c = m[c];
        }
        return message;
    }
};
```

### 复杂度分析

时间复杂度：$O(n + m)$，其中 $n$ 是字符串 $key$ 的长度，$m$ 是字符串 $message$ 的长度。

空间复杂度：$O(|\sum|)$ 或者 $O(m+|\sum|)$，其中 $|\sum|$ 是字符集的大小，本题中 $|\sum| = 26$。如果不能原地修改字符串，那么还需要额外的存储空间来存储译文，因此时间复杂度是 $O(m + |\sum|)$。