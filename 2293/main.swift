class Solution {
    func minMaxGame(_ nums: [Int]) -> Int {
        var nums = nums
        var n = nums.count
        if n == 1 { return nums[0] }
        repeat {
            var t: [Int] = []
            for i in 0..<n/2 {
                if i % 2 == 0 {
                    t.append(min(nums[2 * i], nums[2 * i + 1]))
                } else {
                    t.append(max(nums[2 * i], nums[2 * i + 1]))
                }
            }
            nums = t
            n /= 2
        } while (n != 1)
        return nums[0]
    }
}