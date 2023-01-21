class Solution {
    func minSideJumps(_ obstacles: [Int]) -> Int {
        var n = obstacles.count
        var dp = [1, 0, 1]
        var inf = Int(1e9)
        for i in 0..<n {
            var count = inf
            for j in 0...2 {
                if j == obstacles[i] - 1 { 
                    dp[j] = inf
                } else {
                    count = min(count, dp[j])
                }
            }

            for j in 0...2 {
                if j == obstacles[i] - 1 {
                    continue
                }
                dp[j] = min(dp[j], count + 1)
            }
        }
        return dp.min()!
    }
}