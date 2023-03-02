class Solution {
    func prefixCount(_ words: [String], _ pref: String) -> Int {
        var ans = 0
        for word in words {
            if word.hasPrefix(pref) {
                ans += 1
            }
        }
        return ans
    }
}