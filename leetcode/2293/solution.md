题目链接：[2293. 极大极小游戏](https://leetcode.cn/problems/min-max-game/)

## 模拟

设 $n$ 为数组 $nums$ 的长度，当 $n=1$ 时返回第一个元素。否则创建一个新数组 $newNums$， 对于 $newNums$ 每个下标 $i$ ，我们按照奇偶性分别进行赋值求出 $newNums$ 后并赋值给 $nums$ ，直到 $nums$ 仅剩一个元素时返回即可。

Code

```c++
class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        while (n != 1){
            vector<int> t(n / 2);
            for (int i = 0; i < n / 2; i ++) {
                if (i % 2 == 0) {
                    t[i] = min(nums[2 * i], nums[2 * i + 1]);
                } else {
                    t[i] = max(nums[2 * i], nums[2 * i + 1]);
                }
            }
            nums = t;
            n /= 2;
        }
        return nums[0];
    }
};
```

### 复杂度分析

时间复杂度：$O(n)$，其中 $n$ 为数组 $newNums$ 的长度，第一次循环遍历整个数组 $O(n)$，第二次数据规模减半 $O(\frac{n}{2})$，所以整体时间复杂度为 $O(n) + O(\frac{n}{2})+O(\frac{n}{4})+...+O(1) = O(n)$。

空间复杂度：$O(n)$，需要存储每次循环的数据。

