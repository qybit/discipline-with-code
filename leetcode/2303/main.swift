class Solution {
    func calculateTax(_ brackets: [[Int]], _ income: Int) -> Double {
        if income == 0 { return 0.0 }
        var total = 0
        var preUpper = 0
        for bracket in brackets {
            var upper = bracket[0], rate = bracket[1]
            if income >= upper {
                total += (upper - preUpper) * rate
                preUpper = upper
            } else {
                total += (income - preUpper) * rate;
                break
            }
        }
        return Double(total) / 100
    }
}