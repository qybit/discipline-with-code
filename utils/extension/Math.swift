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

    // 反转整数
    func reverse() -> Int {
        var x = self
        var t = 0
        while (x != 0) {
            t = t * 10 + x % 10
            x /= 10
        }
        return t
    }
}