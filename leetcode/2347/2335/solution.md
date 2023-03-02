题目链接：[2335. 装满杯子需要的最短总时长](https://leetcode.cn/problems/minimum-amount-of-time-to-fill-cups/)

## 贪心

现存在一饮水机，每秒钟可以装满 $2$ 杯不同类型的水或者 $1$ 杯任意类型的水。为了更快的装满所有杯子中的水，每秒钟都要选择需要杯子数量最大的杯子。$amount[i]$ 可以看成某个杯子的容量，在装水之前对杯子容量进行排序，选择最大和第二大容量的杯子装水即可。

Code

```c++
class Solution {
public:
    int fillCups(vector<int>& amount) {
        int ans = 0;
        while (true) {
            sort(amount.begin(), amount.end());
            if (amount[2] <= 0) {
                break;
            }
            amount[2]--, amount[1]--;
            ans ++;
        }
        return ans;
    }
};
```

### 复杂度分析

时间复杂度：$O(k \times nlogn)$，其中 $k$ 是数组之和最大值为 $300$，其中 $n$ 是数组 $amount$ 长度，本题中 $n = 3$。

空间复杂度：$O(1)$。