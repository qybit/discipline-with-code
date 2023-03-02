题目链接：[1405. 最长快乐字符串](https://leetcode.cn/problems/longest-happy-string/)

## 贪心

「快乐字符串」定义为不包含任何 `aaa`，`bbb` 或 `ccc` 的子串，可以直接模拟这个过程：

- 对 $a$ ，$b$ 和 $c$ 进行排序处理，每次取最大值尝试添加到答案中，且当前最大值代表的字符不会连续两次出现。

> ​	判断连续出现两次的做法：直接取末位，以及倒数第二位字符进行判断

- 当答案字符串长度没有发生变化时，表示无法再增加「快乐字符串」的长度，退出即可。

Code

```c++
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans;
        vector<pair<int,char>> m{{a, 'a'}, {b, 'b'}, {c, 'c'}};
        while (true) {
            sort(rbegin(m), rend(m));
            int pre_sz = ans.size();
            for (auto& [cnt, c] : m) {
                if (cnt <= 0
                    || ans.size() >= 2 && c == ans.back() && c == ans[ans.size() - 2])
                    continue;
                ans += c;
                cnt --;
                break;
            }
            if (pre_sz == ans.size()) break;
        }
        return ans;
    }
};
```

### 复杂度分析

时间复杂度：$O((a + b + c) ClogC)$，其中 $C$ 是 `a` ，`b`，`c` 组成的数组，其中每次模拟都会进行一次排序 $O(ClogC)$，排序完成后还要对 `a`，`b`，`c` 进行选择，最多选择 $O(a + b + c)$。

空间复杂度：$O(C)$。