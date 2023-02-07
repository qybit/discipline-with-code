

题目链接：[1604. 警告一小时内使用相同员工卡大于等于三次的人](https://leetcode.cn/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/)

## 哈希表+排序

根据题意找到某个员工在一小时内使用员工卡次数大于等于3次的员工。使用哈希表记录员工和员工所有打卡记录，并对其打卡记录进行排序操作使得所有记录严格递增，当三个连续的打卡时间中最大元素和最小元素不超过 $60$ 分钟则表示该员工一小时的打卡次数至少为3次。其中对打卡时间进行转换，将其转化为分钟制即可解决隔天打卡的情况。

Code

```c++
class Solution {
public:

    int convert(string time) {
        int hours = (time[0] - '0') * 10 + (time[1] - '0');
        int mins = (time[3] - '0') * 10 + (time[4] - '0');
        return hours * 60 + mins;
    }

    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, vector<int>> m;
        int n = keyName.size();
        for (int i = 0; i < n; i++) {
            m[keyName[i]].emplace_back(convert(keyTime[i]));
        }
        vector<string> ans;
        for (auto &[k, v] : m) {
            int sz = v.size();
            bool flag = false;
            if (sz > 2) {
                sort(v.begin(), v.end());
                for (int i = 2; i < sz; i ++) {
                    if (v[i] - v[i - 2] <= 60) {
                        flag = true;
                        break;
                    }
                }
            }
            if (flag) {
                ans.emplace_back(k);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
```

### 复杂度分析

时间复杂度：$O(nlogn)$，其中 $n$ 表示为数组 $keyName$ 和 $keyTime$ 的长度。

首先遍历这两个数组，将其员工名字和打卡时间分别进行记录，遍历的时间复杂度为 $O(n)$，存入哈希表的操作 $O(n)$，因此这部分时间复杂度为 $O(n)$。

然后遍历哈希表，对于每一位员工首先对其打卡时间进行排序使记录严格递增 $O(nlogn)$，当打卡时间数量大于 $2$ 时此时需要遍历打卡时间数组 $v$ 校验连续三个打卡时间中最大值和最小值是否不超过 $60$ 分钟，最坏的情况下需要遍历整个数组 $O(n)$。

最后返回答案之前，还要对答案数组进行排序 $O(nlogn)$。因此总的时间复杂度为 $O(nlogn)$。

空间复杂度：$O(n)$，存储哈希表数据空间。