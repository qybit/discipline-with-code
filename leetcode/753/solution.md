题目链接：[753. 破解保险箱](https://leetcode.cn/problems/cracking-the-safe/)

## 回溯法

中文题目描述的比较生硬，这个题目实际上的意思是，保险箱的密码是 $n$ 位数，其中每位数都是 $0,1,..,k-1$ 中的一个数。

题意分析，当 $n = 2$，$k=2$ 时：

1. 此时存在可行密码，`00`、`01`、`10` 和 `11`  四种情况，那么最短字符串存在 `00110 `、 `01100`、`10011` 和 `11001`；
2. 由于保险箱只能记住最后输入的 $n$ 位数字，且能打开保险箱，换言之也最短字符串必须满足输入任意其中 $n$ 位连续子串就保证可以打开保险箱；
3. 比如先输入 `00`，取上一个密码的最后一个 `0` 作为下一个密码的前缀，那么此时再输入 `1` 此时保险箱可以识别出正确密码，如果不行，则对剩余字符串进行命中；

具体做法，将可行答案看成一个节点，其中节点个数是 $k^n$ 个，假设存在起点字符串 $n$ 个 `0` ，我们按照上述思路，取上一个节点的末尾 $n - 1$ 个字符串作为下一个密码的前缀，并枚举最后一个位置的可能密码。

Code

```c++
class Solution {
public:
    string ans; // 最短字符串
    int maxNodes; // 全部节点数量
    int n, k;
    unordered_set<string> visited; // 存在的答案字符串数量

    bool dfs(string s) {
        if (visited.size() == maxNodes) {
            ans = s;
            return true;
        }

        string prefix = s.substr(s.size() - n + 1); // 取上一个密码的前n-1位作为下一个答案字符串的前缀
        for (int i = 0; i < k; i ++) {
            string node = prefix + to_string(i); // 可能存在的密码字符串
            if (visited.count(node) == 0) { // 去重
                s = s + to_string(i); // 添加后缀，后面n位字符串是答案字符串
                visited.insert(node);
                if (dfs(s)) {
                    return true;
                }
                visited.erase(node);
                s.pop_back();
            }
        }
        return false;
    }

    string crackSafe(int _n, int _k) {
        n = _n, k = _k;
        maxNodes = pow(k, n);
        ans.resize(n, '0');
        visited.insert(ans);
        dfs(ans);
        return ans;
    }
};
```

### 复杂度分析

时间复杂度：$O(n \times k^n)$，其中 $n$ 为密码个数，$k$ 为每位密码的数值（$k \in [0,k-1]$），我们从节点 $00..0$ 开始枚举，每次枚举 $k$ 次找下一个密码可能存在的后缀 $O(k)$，而每次枚举出新密码后还需要进行去重操作 $O(n)$，对于新的密码添加到答案字符串后，还要重复上述操作，因此时间复杂度为 $O(n \times k^n)$。

空间复杂度：$O(n \times k^n)$ 。