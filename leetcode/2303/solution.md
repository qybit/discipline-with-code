题目链接：[2303. 计算应缴税款总额](https://leetcode.cn/problems/calculate-amount-paid-in-taxes/)

## 模拟

设 $i$ 为 $brackets$ 的第 $i(i > 0)$ 个下标，其中 $brackets[i] = [upper_i,percent_i]$ ，$upper_i$ 表示为税级的上限，征收的税率为 $percent_i$，税级按上限从低到高排序 $upper_{i-1} < upper_i$ 

根据税款计算方式：

- 不超过 $upper_i$ 的收入按税率 $percent_i$ 缴纳
- 接着按照 $upper_i - upper_{i-1}$ 的部分按税率 $percent_i$ 缴纳
- 然后 $upper_{i+1} - upper_i$ 的部分按税率 $percent_{i+1}$ 缴纳
- 以此类推

设 $total$ 为需要缴纳的税金总额，$preUpper$ 为上一税级的上限初始为 $0$ 。如果 $income \ge upper$ 表示收入已达到当前税级上限，就需要缴纳 $(upper - preUpper) * percent$ 部分的税额。否则就表示收入未达到上限，我们只需要计算收入大于等于 $preUpper$ 的部分即可，这部分需要缴纳的税额为 $(income - preUpper) * rate$。

Code

Swift

```swift
class Solution {
    func calculateTax(_ brackets: [[Int]], _ income: Int) -> Double {
        if income == 0 { return 0.0 }
        var total = 0
        var preUpper = 0
        for bracket in brackets {
            var upper = bracket[0], rate = bracket[1]
            if income >= upper {
                total += (upper - preUpper) * rate
                preUpper = upper
            } else {
                total += (income - preUpper) * rate;
                break
            }
        }
        return Double(total) / 100
    }
}
```

Cpp

```c++
class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        if (income == 0) return 0.0;
        int total = 0;
        int preUpper = 0;
        for (auto &bracket : brackets) {
            int upper = bracket[0];
            double rate = bracket[1];
            if (income >= upper) {
                total += (upper - preUpper) * rate;
                preUpper = upper;
            } else {
                total += (income - preUpper) * rate;
                break;
            }
        }
        return (double)total / 100;
    }
};
```

### 复杂度分析

时间复杂度：$O(n)$，其中 $n$ 表示为数组 $brackets$ 的长度，我们最多只会遍历一次数组来计算各个税级需要缴纳的税额。

空间复杂度：$O(1)$。

