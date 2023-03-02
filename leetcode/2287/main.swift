class Solution {
    func rearrangeCharacters(_ s: String, _ target: String) -> Int {
        var count1 = Dictionary<Character, Int>(), count2 = Dictionary<Character, Int>();
        for c in s {
            count1[c] = (count1[c] ?? 0) + 1
        }
        for c in target {
            count2[c] = (count2[c] ?? 0) + 1
        }
        var ans = Int.max
        for c in target {
            let x = count1[c] ?? 0, y = count2[c]!
            ans = min(ans, x / y)
        }
        return ans
    }
}