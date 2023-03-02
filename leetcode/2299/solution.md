题目链接：[2299. 强密码检验器 II](https://leetcode.cn/problems/strong-password-checker-ii/)

## 模拟

按照题意，分别密码中的各个字符是否满足以下条件即可。

对于密码至少有 `8` 个字符，判断 $password$ 长度是否小于 8 即可。

对于密码至少有 「一个小写英文」、「一个大写英文」、「一个数字」和「一个特殊字符」，分别设 $ hasLower$ 、 $hasUpper$ 、$hasDigit$ 和 $hasSpecial$ 表示，我们可以借助 ASCII 码表，或者自带的 API 进行判断即可。

对于密码不包含 `2` 个连续相同的字符，我们直接判断当前下标 $i（i > 0）$ 的前一个字符是否相等即可，如果相等返回 `false`，否则进行遍历字符串。

Code

```c++
class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        int n = password.size();
        if (n < 8) return false;
        bool hasDigit = false, hasUpper = false, hasLower = false, hasSpecial = false;
        string speical = "!@#$%^&*()-+";
        for (int i = 0; i < n; i ++) {
            if (i > 0 && password[i] == password[i-1]) {
                return false;
            }
            char c = password[i];
            if (isdigit(c)) {
                hasDigit = true;
            } else if (isupper(c)) {
                hasUpper = true;
            } else if (islower(c)) {
                hasLower = true;
            } else if (speical.find(c) != string::npos) {
                hasSpecial = true;
            }
        }
        return hasDigit && hasUpper && hasLower && hasSpecial;
    }
};
```

### 复杂度分析

时间复杂度：$O(n + |\sum|)$，其中 $n$ 为字符串 $password$ 的长度，$|\sum|$ 表示特殊字符集的长度，我们至多只会遍历一次字符串。

空间复杂度：$O(|\sum|)$，存储特殊字符集的空间。