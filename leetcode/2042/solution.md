题目链接：[2042. 检查句子中的数字是否递增](https://leetcode.cn/problems/check-if-numbers-are-ascending-in-a-sentence/)

## 方法一：字符串分割

字符串 $s$ 是由多个 $token$ 组成，$token$ 间用单个空格分隔开，为了检查 $token$ 中属于数字的那部分在字符串中出现的顺序是否是严格递增的。我们可以按照空格分割字符串，得到一个由数字（数字范围在 $[2,100]$ 之间，且不含前导 $0$）组成的子序列，并遍历字符串检查是否严格递增。

具体实现上，使用 $split$ 方法获得全部 $token$ 列表，并过滤出数字子序列，然后检查是否严格递增即可。

Code

```c++
class Solution {
public:

    int s2i(const string_view &s) {
        int num = 0;
        for (char c : s) {
            num = num * 10 + (c - '0');
        }
        return num;
    }

    vector<int> split(const string &src, char target)
    {
        vector<int> ret;
        string_view s(src);
        int pos = 0;
        int n = s.size();
        while (pos < n)
        {
            while (pos < n && s[pos] == target)
            {
                pos++;
            }
            int start = pos;
            while (pos < n && s[pos] != target)
            {
                pos++;
            }
            if (pos > start)
            {
                // t一定不为空，过滤出数字
                string_view t = s.substr(start, pos - start);
                if (isdigit(t[0])) {
                    ret.push_back(s2i(t));
                }
            }
        }
        return ret;
    }

    bool areNumbersAscending(string s) {
        vector<int> nums = split(s, ' ');
        for (int i = 1; i < nums.size(); i ++) {
            if (nums[i - 1] >= nums[i]) {
                return false;
            }
        }
        return true;
    }
};
```

### 复杂度分析

时间复杂度：$O(n)$，其中 $n$ 为字符串 $s$ 的长度，我们遍历字符串并按照空格分割字符串 $O(n)$，过滤部分在获得子字符串时已经完成 $O(n)$，最后遍历子数组 $O(n)$，我们最多遍历常数次数组。

空间复杂度：$O(n)$，需要存储分割后字符串数组。

## 方法二：直接遍历

字符串 $s$ 中的字符仅存在三种情况，空格，小写字母和数字。需要检查 $s$ 中出现的数字是否从左到右严格递增，所以在遍历过程中只需要关注数字部分即可。设 $prev$ 为遍历过程中上一个下标中出现的数字大小，当遍历到某个下标 $pos$ 字符数字大小 $s[pos] \in [0,9]$ 属于时，计算出当前下标 $pos$ 所属数字 $cur$ 的大小，并与 $prev$ 进行比较如果 $cur > prev$ 则继续遍历，否则结束遍历返回 $false$。当我们遍历完字符串后，则表示 $s$ 中出现过的数字都满足严格递增。

Code

```c++
class Solution {
public:
    bool areNumbersAscending(string s) {
        int prev = 0;
        int pos = 0, n = s.size();
        while (pos < n) {
            if (isdigit(s[pos])) {
                int cur = 0;
                while (pos < n && isdigit(s[pos])) {
                    cur = cur * 10 + s[pos] - '0';
                    pos ++;
                }
                if (cur <= prev) {
                    return false;
                }
                prev = cur;
            } else {
                pos ++;
            }
        }
        return true;
    }
};
```

### 复杂度分析

时间复杂度：$O(n)$，其中 $n$ 为字符串的长度，我们最多遍历一次字符串。

空间复杂度：$O(1)$。