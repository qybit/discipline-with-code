class Solution {
    func largestWordCount(_ messages: [String], _ senders: [String]) -> String {
        var nameDict: [String:Int] = [:]
        for (i, sender) in senders.enumerated() {
            var msgCount = messages[i].count(" ") + 1
            nameDict[sender] = (nameDict[sender] ?? 0) + msgCount
        }
        var maxCount = 0
        var ans = ""
        for (k, v) in nameDict {
            if (v > maxCount) {
                maxCount = v
                ans = k
            } else if (v == maxCount) {
                if (k > ans) {
                    ans = k
                }
            }
        }
        return ans
    }
}

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
}