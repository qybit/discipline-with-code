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