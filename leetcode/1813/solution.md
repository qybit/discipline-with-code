题目链接：[1813. 句子相似性 III](https://leetcode.cn/problems/sentence-similarity-iii/)

## 双指针

如果两个句子 $sentence1$ 和 $sentence2$ ，向其中任意一个句子插入一个任意的句子（可以是空句子）即可得到另一个句子，那么可以称这两个句子是相似的。需要关注的是我们只能插入一次，那么插入的位置可以有前面、中间和后面。也就是说，这两个句子的需要满足如下情况才能相似：

- $sentence1$ 和 $sentence2$ ，其中一个句子是另一个句子的前缀，这时我们在句子长度短的后面插入剩余句子即可相等。
- $sentence1$ 和 $sentence2$ ，其中一个句子是另一个句子的后缀， 这时我们在句子长度短的前面插入剩余句子即可相等。
- $sentence1$ 和 $sentence2$ ，两个句子的前缀和后缀是相等的，这时我们在句子长度短的中间插入一个句子即可相等。

实现上，我们按照空格分割字符串得到数组 $s1$ 和 $s2$ ，设 $i$ 代表数组的最左边，最多有 $i$ 个字符相同，表示为在短句子后面插入一个句子。设 $j$ 代表数组的最右边，最多有 $j$ 个字符相同，表示为在短句子前面插入一个句子。其中 $i + j$ 代表前缀后数量之和，最多有 $min(s1.length, s2.length)$，表示需要在短句子中间插入一个句子。

Code

```c++
class Solution {
public:

    vector<string_view> split(const string& src, char target) {
        vector<string_view> ret;
        string_view s(src);
        int pos = 0;
        int n = s.size();
        while (pos < n) {
            while (pos < n && s[pos] == target) {
                pos ++;
            }
            int start = pos;
            while (pos < n && s[pos] != target) {
                pos ++;
            }
            if (pos > start) {
                ret.emplace_back(s.substr(start, pos - start));
            }
        }
        return ret;
    }

    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string_view> s1 = split(sentence1, ' ');
        vector<string_view> s2 = split(sentence2, ' ');
        int m = s1.size(), n = s2.size();
        int i = 0, j = 0;
        // 前缀相同统计
        while (i < m && i < n && s1[i] == s2[i]) {
            i ++;
        }
        // 后缀相同统计
        while (j < m - i && j < n - i && s1[m - j - 1] == s2[n - j - 1]) {
            j ++;
        }
        // 前后缀相同统计
        return i + j == min(m, n);
    }
};
```

### 复杂度分析

时间复杂度：$O(m + n)$，其中 $m$ 表示 $sentence1$ 的长度，$n$ 表示为 $sentence2$ 的长度，我们需要按照空格分割两个数组，所以时间复杂度为 $O(m+n)$。

空间复杂度：$O(m+n)$，我们需要存储分割后的字符串空间。