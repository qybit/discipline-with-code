题目链接：[1817. 查找用户活跃分钟数](https://leetcode.cn/problems/finding-the-users-active-minutes/)

题目要求统计对于 $(1 \le j \le k)$ 的每个 $j$ 计算用户活跃分钟数等于 $j$ 的用户数。需要首先获得每个用户的活跃分钟数，并计算出每个活跃数等于 $j$ 的用户。

由于同一个用户的每次执行操作的时间不重复计算，因此需要使用哈希表记录每个用户的执行操作的时间，哈希表的键为用户编号，值为该用户执行操作的时间，为了不重复计算全部执行操作的时间，也需要哈希集合保证每个分钟的操作仅记录一次。

当遍历统计完数组 $logs$ 后，我们不关注具体是哪些用户的活跃分钟数恰好等于 $j$ ，所以在遍历哈希表时只需要关注值即可。

Code

C++

```c++
class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int,unordered_set<int>> m;
        for (auto &&log : logs) {
            int id = log[0], time = log[1];
            m[id].emplace(time);
        }
        vector<int> ans(k);
        for (auto &[_, minutes] : m) {
            int ops = minutes.size();
            ans[ops - 1] ++;
        }
        return ans;
    }
};
```

Swift

```swift
class Solution {
    func findingUsersActiveMinutes(_ logs: [[Int]], _ k: Int) -> [Int] {
        var map: [Int: Set<Int>] = [:]
        for log in logs {
            let id = log[0], time = log[1]
            map[id] = (map[id] ?? Set<Int>())
            map[id]!.insert(time)
        }
        var ans = [Int](repeating: 0, count: k)
        for (_, minutes) in map {
            var sz = minutes.count
            ans[sz - 1] += 1
        }
        return ans
    }
}
```

### 复杂度分析

时间复杂度：$O(n + k)$，其中 $n$ 是数组 $logs$ 的长度，$k$ 是给定的整数。遍历数组 $logs$ 并使用哈希表记录每个用户的活跃分钟需要 $O(n)$ 的时间，创建答案数组和遍历哈希表更新答案需要 $O(n + k)$，因此时间复杂度是 $O(n + k)$。

空间复杂度：$O(n)$，其中 $n$ 是数组 $logs$ 的长度。哈希表需要 $O(n)$ 的空间。