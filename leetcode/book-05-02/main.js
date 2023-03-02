/**
 * @param {number} num
 * @return {string}
 */
var printBin = function(num) {
    let ans = '0.'
    while (num != 1) {
        num *= 2
        ans += parseInt(num)
        if (ans.length > 32) return 'ERROR'
        if (num > 1) {
            num -= 1
        }
    }
    return ans
};