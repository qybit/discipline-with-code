class Solution {
    func countEven(_ num: Int) -> Int {
        var ans = 0
        for x in 1...num {
            if x.getDigitSum() % 2 == 0 {
                ans += 1
            }
        }
        return ans
    }
}

extension Int {
    // 获取每位数字之和
    func getDigitSum() -> Int {
        var num = self
        var s = 0
        while (num != 0) {
            s += num % 10
            num /= 10
        }
        return s
    }
}