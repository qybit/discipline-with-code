题目链接：[670. 最大交换](https://leetcode.cn/problems/maximum-swap/)

## 模拟

根据题意直接进行模拟交换任意两位数字，并比较记录最大值。由于数据范围 $[0, 10^8]$ ，在交换任意两位数字后也不需要考虑溢出的问题。

Code

```c++
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        int ans = num;
        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                swap(s[i], s[j]);
                ans = max(ans, stoi(s));
                swap(s[i], s[j]);
            }
        }
        return ans;
    }
};
```

### 复杂度分析

时间复杂度：$O(log^3num)$，我们枚举第一个交换位置 $i$，依次再枚举第二个位置 $j$，当交换了 $i$ 和 $j$ 之后再转换成数字 $O(lognum)$，因此时间复杂度为 $O(log^3num)$。

空间复杂度：$O(lognum)$，存储字符串数字的空间。

