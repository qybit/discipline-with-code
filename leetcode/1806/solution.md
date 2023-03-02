题目链接：[1806. 还原排列的最少操作步数](https://leetcode.cn/problems/minimum-number-of-operations-to-reinitialize-a-permutation/)

## 模拟

根据题意进行操作即可，直到数组 $perm$ 还原到 $perm[i] = i$ 的状态。而且数据量仅有 $1000$，因此直接模拟不会超时。

Code

```c++
class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> arr(n);
        vector<int> perm(n);
        int ans = 0;
        for (int i = 0; i < n; i ++) perm[i] = i;
        do {
            for (int i = 0; i < n; i ++) {
                if (i % 2 == 0) {
                    arr[i] = perm[i / 2];
                } else {
                    arr[i] = perm[n / 2 + (i - 1) / 2];
                }
            }
            perm = arr;
            ans ++;
        } while (valid(perm));
        return ans;
    }

    bool valid(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != i) return true;
        }
        return false;
    }
};
```

### 复杂度分析

时间复杂度：$O(n^2)$，其中 $n$ 为数组 $perm$ 的长度，我们需要需要至多操作 $n$ 次即可还原数组。每次操作后都需要检查一次数组 $perm$。

空间复杂度：$O(n)$，需要存储数组 $perm$。

