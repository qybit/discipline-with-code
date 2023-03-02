class Solution {
    func strongPasswordCheckerII(_ password: String) -> Bool {
        let n = password.count
        if n < 8 {
            return false
        }
        var hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false
        let special = "!@#$%^&*()-+"
        for (index, c) in password.enumerated() {
            if index > 0 && password.getByIndex(index) == password.getByIndex(index - 1) {
                return false
            }
            let ch = String(c)
            if ch.isDigit() {
                hasDigit = true
            } else if ch.isUpper() {
                hasUpper = true
            } else if ch.isLower() {
                hasLower = true
            } else if (special.contains(ch)) {
                hasSpecial = true
            }
        }
        return hasLower && hasUpper && hasDigit && hasSpecial
    }
}

// 扩展String方法
extension String
{
    // 根据索引获取
    func getByIndex(_ index: Int) -> Character {
        let idx = self.index(self.startIndex, offsetBy: index);
        return self[idx]
    }

    // 判断是否为大写字符
    func isUpper() -> Bool
    {
        let ASCIIValue = Int(self.unicodeScalars.first!.value)
        return (ASCIIValue >= 65 && ASCIIValue <= 90) ? true : false
    }
    // 判断是否为小写字符
    func isLower() -> Bool
    {
        let ASCIIValue = Int(self.unicodeScalars.first!.value)
        return (ASCIIValue >= 97 && ASCIIValue <= 122) ? true : false
    }
    // 判断是否为数字字符
    func isDigit() -> Bool
    {
        let ASCIIValue = Int(self.unicodeScalars.first!.value)
        return (ASCIIValue >= 48 && ASCIIValue <= 57) ? true : false
    }
}

