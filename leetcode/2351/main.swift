class Solution {
    func repeatedCharacter(_ s: String) -> Character {
        var hashSet: Set<Character> = Set<Character>()
        for c in s {
            if hashSet.contains(c) {
                return c
            }
            hashSet.insert(c)
        }
        return " "
    }
}