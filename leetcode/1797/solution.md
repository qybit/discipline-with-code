题目链接：[1797. 设计一个验证系统](https://leetcode.cn/problems/design-authentication-manager/)

## 哈希表

维护一个全局 $Map$ 保存 $tokenId$ 和过期时间 $expiredTime$，当生成、刷新和计算过期时间时查询 $Map$ 即可。

Code

```c++
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


AuthenticationManager.prototype.countUnexpiredTokens = function(currentTime) {
    let ans = 0
    for (let [_, expiredTime] of this.userAlive) {
        if (expiredTime <= currentTime) continue
        ans ++
    }
    return ans
};

```

### 复杂度分析

时间复杂度：$O(n)$，构造函数 $O(1)$，生成令牌 $O(1)$，刷新令牌 $O(1)$，计算未过期令牌 $O(n)$。

空间复杂度：$O(n)$。