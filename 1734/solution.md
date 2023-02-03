题目链接：[1734. 解码异或后的排列](https://leetcode.cn/problems/decode-xored-permutation/)

根据题意求 $perm$ 数组，它是 $1 ....n$ 个正整数的排列，且 $n$ 是一个奇数。加密数组 $encoded$ 数组是由 $encoded[i]=perm[i] \bigoplus perm[i+1]$ 构成，且长度为 $n - 1$。

$n$ 是已知的，所以 $1 ... n$ 的异或结果也是已知的。假设 $perm = [a, b,c,d,e]$，存在 $encoded=[f,g,h,i]$：

- $f = a \bigoplus b$
- $g = b \bigoplus c$
- $h = c \bigoplus d$
- $i = d \bigoplus e$

设 $total = a \bigoplus b \bigoplus c \bigoplus ... \bigoplus z$，那么可以发现 $encoded$ 中 $g \bigoplus i = b \bigoplus c \bigoplus d \bigoplus e$，通过 $encoded$ 中奇数下标的异或值跟 $total$ 即可确认 $perm$ 数组中的第一个位置的值，其他位置的值同理。当我们确认某个位置的值之后，再借助 $encoded[i] = perm[i] \bigoplus perm[i+1]$ 即可还原数组 $perm$。

Code

```c++
class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int sz = encoded.size();
        int n = sz + 1;
        int a = 0;
        for (int i = 1; i <= n; i ++) {
            a ^= i;
        }
        for (int i = 1; i < sz; i += 2) {
            a ^= encoded[i];
        }
        vector<int> ans(n);
        ans[0] = a;
        for (int i = 0; i < n - 1; i ++) {
            ans[i + 1] = ans[i] ^ encoded[i];
        }
        return ans;
    }
};
```

### 复杂度分析

时间复杂度：$O(n)$，其中 $n$ 是数组 $perm$ 的长度。

空间复杂度：$O(n)$，其中 $n$ 是存储答案数组的长度。