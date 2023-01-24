class Solution {
    func countPoints(_ points: [[Int]], _ queries: [[Int]]) -> [Int] {
        var ans: [Int] = []
        var n = queries.count
        for q in queries {
            var rx = q[0], ry = q[1], d = q[2]
            var count = 0
            for p in points {
                var x = p[0], y = p[1]
                var isIn = (rx - x) * (rx - x) + (ry - y) * (ry - y) <= d * d
                if isIn {
                    count += 1
                }
            }
            ans.append(count)
        }
        return ans
    }
}