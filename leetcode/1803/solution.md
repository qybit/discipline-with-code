题目链接：[1803. 统计异或值在范围内的数对有多少](https://leetcode.cn/problems/count-pairs-with-xor-in-a-range/)

## 暴力搜索

根据题意计算满足 `low <= (nums[i] XOR nums[j]) <= high` 的 `(i, j)` 数对。可以很轻松的写出 $N^2$ 时间复杂度的算法来，固定一个下标 $i$ ，枚举另一个下标 $j$ 即可。但是这道题的数据量达到了 $10^4$ ，不足以通过本题。

Code

```c++
class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n; i ++) {
            int x = nums[i];
            for (int j = i + 1; j < n; j ++) {
                int y = nums[j];
                if (low <= (x ^ y) && (x ^ y) <= high) {
                    res ++;
                }
            }
        }
        return res;
    }
};
```

###  复杂度分析

时间复杂度：$O(N^2)$ ，其中 $N$ 为数组 $nums$ 长度，对于数组每个元素至多遍历 $N - 1$ 次。

空间复杂度：$O(1)$。

## 字典树

观察 `low <= (nums[i] XOR nums[j]) <= high`，可以表示 $f(x)$ 为 $nums$ 数组中有多少对 $(i, j)$ 小于等于 $x$，那么问题求解就转换为 $f(high) - f(low - 1)$。

本题数据范围为 $[1, 2 * 10^4]$ ，可以将数组里的每个元素都看成 $15$ 位仅包含 0 和 1的二进制字符串（不满15位的补充前导0），将字符串存入到字典树中。这15个二进制位从低位到高位依次编号 $0,1,2,···,14$。字典树每记录一个数字，都表示以根节点到当前节点为前缀的字符串个数，我们将路径上的所有节点的数字加 $1$。

由于 $0 \le j \lt i \le nums.length$ 限制，考虑枚举 $a_i$，求得存在多少个 $a_j(j<i)$ 使得 $a_i \bigoplus a_j \le x$，其中 $\bigoplus$ 表示异或操作。对于 $a_i$ 而言，$a_j (0 \le j \lt i)$ 都已经加入到了字典树中，此处则是优化掉了消耗 $O(N)$ 时间枚举下标 $j$ 的操作。因此只需要统计出字典树中的元素 $a_j $ 与 $a_i$ 异或小于等于 $x$ 的数量即可

如何判断 $a_j $ 与 $a_i$ 异或结果小于等于 $x$ ？我们已知 $x$ 和 $a_i$，在遍历字典树的过程中是从高位到低位依次插入字典树中，假设枚举到了第 $k$ 个位二进制位时：

- 如果 $x$ 的第 $k$ 位为 $1$ ，设 $r$ 为 $a_i$ 的第 $k$ 个二进制位，那么此时 $r$ 的子节点中记录的数字，就是使得 $a_j \bigoplus a_i \lt x$ 的个数，表示结果一定小于 $x$ ，此时我们选择 $r \bigoplus 1$ 节点，保证路径上的数值与 $a_i$ 异或后前缀与 $x$ 相同。
- 如果 $x$ 的第 $k$ 位为 $0$，此时不存在 $a_j \bigoplus a_i \lt  x$，设 $r$ 为 $a_i$ 的第 $k$ 个二进制位，我们需要要向 $r$ 节点走，这保证了路径上的数值与 $a_i$ 异或后前缀与 $x$ 相同

如果在遍历的过程中，存在某个子节点不存在而无法继续的时候，需要立刻返回统计到的 $a_j$ 的个数。假如遍历到了最后一个节点了，说明存在使得 $a_j \bigoplus a_i = x$ 那么此时也要加上最后一个节点的个数一并返回。

Code

```c++
struct Tire {
    Tire *root = nullptr;
    array<Tire*, 2> son {nullptr, nullptr};
    int sum;

    Tire():sum(0) {}
};

class Solution {
private:
    Tire* root = nullptr;
public:

    void insert(int x) {
        Tire* cur = root;
        for (int k = 14; k >= 0; k --) {
            int b = (x >> k) & 1;
            if (cur->son[b] == nullptr) {
                cur->son[b] = new Tire();
            }
            cur = cur->son[b];
            cur->sum++;
        }
    }

    int get(int num, int x) {
        Tire* cur = root;
        int sum = 0;
        for (int k = 14; k >= 0; k --) {
            int r = (num >> k) & 1;
            if ((x >> k) & 1) {
                // 如果x第k位是1，假设字典树中的第k位存在且与num的第k位相同才能使异或结果小于等于x
                if (cur->son[r] != nullptr) {
                    sum += cur->son[r]->sum;
                }
                // 如果字典树中第k位对应的不存在相反的二进制位，那么没有数可以使得异或结果等于x
                if (cur->son[r ^ 1] == nullptr) {
                    return sum;
                }
                cur = cur->son[r ^ 1];
            } else {
                // 如果x第k位是0，当且仅当字典树中的数与num相同才能使得结果小于等于x
                if (cur->son[r] == nullptr) {
                    return sum;
                }
                cur = cur->son[r];
            }
        }
        sum += cur->sum;
        return sum;
    }

    int f(vector<int>& nums, int x) {
        root = new Tire();
        int res = 0;
        for (int i = 1; i < nums.size(); i ++) {
            insert(nums[i - 1]);
            res += get(nums[i], x);
        }
        return res;
    }

    int countPairs(vector<int>& nums, int low, int high) {
        return f(nums, high) - f(nums, low - 1);
    }
};
```

### 复杂度分析

时间复杂度：$O(NlogC)$，其中 $N$ 为数组 $nums$ 的长度，$C$ 表示为常数，其中最大不会超过 $2^{15}$ 。我们需要将 $a_0,a_1,a_2,...,a_{N-2}$ 依次加入到字典树中，并且以 $a_1,a_2,...a_N$ 在字典树上遍历，每次操作时间复杂度为 $O(logC)$，因此时间复杂度为 $O(NlogC)$。

空间复杂度：$O(NlogC)$。每个元素在字典树中占用 $O(logC)$ 的空间，所有空间复杂度为 $O(NlogC)$。