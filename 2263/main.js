/**
 * @param {number[][]} items1
 * @param {number[][]} items2
 * @return {number[][]}
 */
var mergeSimilarItems = function (items1, items2) {
    items1.sort((a, b) => a[0] - b[0])
    items2.sort((a, b) => a[0] - b[0])
    const n = items1.length, m = items2.length
    let i = 0, j = 0
    const ans = []
    while (i < n && j < m) {
        let v1 = items1[i][0], w1 = items1[i][1]
        let v2 = items2[j][0], w2 = items2[j][1]
        if (v1 == v2) {
            ans.push([v1, w1 + w2])
            i++, j++
        } else if (v1 > v2) {
            ans.push([v2, w2])
            j++
        } else {
            ans.push([v1, w1])
            i++
        }
    }
    while (i < n) {
        ans.push(items1[i++])
    }
    while (j < m) {
        ans.push(items2[j++])
    }
    return ans
}