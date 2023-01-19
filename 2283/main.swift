class Solution {
    func digitCount(_ num: String) -> Bool {
        var numCount: [String:Int] = [:]
        for c in num {
            numCount[String(c)] = (numCount[String(c)] ?? 0) + 1
        }
        for (i, c) in num.enumerated() {
            if String(c) != String(numCount[String(i)] ?? 0) {
                return false
            }
        }
        return true
    }
}