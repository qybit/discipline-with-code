/**
 * @param {number} timeToLive
 */
var AuthenticationManager = function(timeToLive) {
    this.timeToLive = timeToLive
    this.userAlive = new Map()
};

/** 
 * @param {string} tokenId 
 * @param {number} currentTime
 * @return {void}
 */
AuthenticationManager.prototype.generate = function(tokenId, currentTime) {
    this.userAlive.set(tokenId, currentTime + this.timeToLive)
};

/** 
 * @param {string} tokenId 
 * @param {number} currentTime
 * @return {void}
 */
AuthenticationManager.prototype.renew = function(tokenId, currentTime) {
    if (!this.userAlive.has(tokenId)) {
        return
    }
    let expiredTime = this.userAlive.get(tokenId)
    // 校验是否过期
    if (expiredTime && expiredTime <= currentTime) {
        return
    }
    // 没过期刷新
    this.userAlive.set(tokenId, currentTime + this.timeToLive)
};

/** 
 * @param {number} currentTime
 * @return {number}
 */
AuthenticationManager.prototype.countUnexpiredTokens = function(currentTime) {
    let ans = 0
    for (let [_, expiredTime] of this.userAlive) {
        if (expiredTime <= currentTime) continue
        ans ++
    }
    return ans
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * var obj = new AuthenticationManager(timeToLive)
 * obj.generate(tokenId,currentTime)
 * obj.renew(tokenId,currentTime)
 * var param_3 = obj.countUnexpiredTokens(currentTime)
 */