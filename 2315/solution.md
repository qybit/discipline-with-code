题目链接：[2315. 统计星号](https://leetcode.cn/problems/count-asterisks/)

## 模拟

根据题意需要返回不在竖线对内的 `'*'` 的数目，可以确定的是字符串起始位置可以是 `'|'` 或空串，那么可以使用一个变量 $flag$ 标记当前遍历的字符是否在竖线对内即可，如果有 `'*'` 就可以加1，最后返回答案即可。

Code

```c++
class Solution {
public:
    int countAsterisks(string s) {
        bool f = true;
        int ans = 0;
        for (char c : s) {
            if (c == '|') {
                f = !f;
            } else if (c == '*'){
                if (f) ans++;
            }
        }
        return ans;
    }
};
```

### 复杂度分析

空间复杂度：$O(n)$，其中 $n$ 是字符串 $s$ 的长度。

空间复杂度：$O(1)$。