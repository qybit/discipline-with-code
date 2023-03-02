题目链接：[2185. 统计包含给定前缀的字符串](https://leetcode.cn/problems/counting-words-with-a-given-prefix/)

## 模拟

根据题意进行模拟即可，遍历字符串数组 $words$ 查找每个元素的前缀与 $pref$ 是否相等。

Code

```c++
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for (auto& word : words) {
            if (word.rfind(pref, 0) == 0) ans ++;
        }
        return ans;
    }
};
```

### 复杂度分析

时间复杂度：$O(n \times m)$，其中 $n$ 为字符串数组的长度，$m$ 为字符串 $pref$ 的长度，我们枚举了全部数组元素 $O(n)$，并遍历每个元素的前缀 $O(m)$ ，因此时间复杂度为 $O(n \times m)$。

空间复杂度：$O(1)$。

