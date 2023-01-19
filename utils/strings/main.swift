// 扩展String方法
extension String {

     // 统计字符出现次数
    func count(_ ch: Character) -> Int {
        var count = 0
        for c in self {
            if c == ch {
                count += 1
            }
        }
        return count
    }

    // 根据索引获取
    func getByIndex(_ index: Int) -> Character {
        let idx = self.index(self.startIndex, offsetBy: index)
        return self[idx]
    }

    // 判断是否为大写字符
    func isUpper() -> Bool {
        let ASCIIValue = Int(self.unicodeScalars.first!.value)
        return (ASCIIValue >= 65 && ASCIIValue <= 90) ? true : false
    }

    // 判断是否为小写字符
    func isLower() -> Bool {
        let ASCIIValue = Int(self.unicodeScalars.first!.value)
        return (ASCIIValue >= 97 && ASCIIValue <= 122) ? true : false
    }

    // 判断是否为数字字符
    func isDigit() -> Bool {
        let ASCIIValue = Int(self.unicodeScalars.first!.value)
        return (ASCIIValue >= 48 && ASCIIValue <= 57) ? true : false
    }
}