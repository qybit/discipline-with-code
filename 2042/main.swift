class Solution {
    func areNumbersAscending(_ s: String) -> Bool {
        var nums = s.split(separator: " ").filter{
            if Int($0) != nil {
                return true
            } else {
                return false
            }
        }.map{Int($0)}
        
        var pre = 0
        for num in nums {
            if num! <= pre {
                return false
            }
            pre = num!
        }
        return true
    }
}