题目链接：[1663. 具有给定数值的最小字符串](https://leetcode.cn/problems/smallest-string-with-a-given-numeric-value/)

## 贪心

初始时，将答案字符串全部用 `a` 进行构造，此时字符串的数值 $d = k - n$。

为了保证字典序最小，我们从后往前的重新构造字符串。每次贪心的将当前位置的字符替换成能够使 $d$ 尽可能小的字符 `z`，直到 $d$ 不超过 $25$ 时停止。最后将剩余的 $d$ 能够替换的字符替换到字符串即可。

Code

Cpp

```c++
class Solution {
public:
    string getSmallestString(int n, int k) {
        string s(n, 'a');
        k -= n;
        for (int i = n - 1; i >= 0; i --) {
            if (k > 25) {
                s[i] = 'z';
                k -= 25;
            } else {
                s[i] = (char)(k + 'a');
                break;
            }
        }
        return s;
    }
};
```

### 复杂度分析

时间复杂度：$O(n)$，其中 $n$ 是字符串的长度。

空间复杂度：$O(1)$。