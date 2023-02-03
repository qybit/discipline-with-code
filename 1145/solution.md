题目链接：[1145. 二叉树着色游戏](https://leetcode.cn/problems/binary-tree-coloring-game/)

## 贪心

当「一号玩家」选择一个值 $x$ 进行染色后，此时「二号玩家」在染色时将会面临三种选择：

1. $x$ 节点的左子树
2. $x$ 节点的右子树
3. $x$ 节点的父节点

为了保证「二号玩家」可以稳定获胜，这三种选择中至少存在一种情况使得可以染色的节点数量大于 $\frac{n}{2}$ ，「二号玩家」才能赢得游戏。

具体做法，直接找到 $x$ 节点，统计其左右子树区域节点的数量和父节点区域的数量，贪心的染色可选择区域中节点数量最多的路径。

Code

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode* xNode = find(root, x); // 找到x节点
        // 左右子树的数量，n - l - r - 1 父节点区域的数量
        int l = count(xNode->left), r = count(xNode->right);
        return max({l, r, n - l - r - 1}) > n / 2;
    }

    TreeNode* find(TreeNode* root, int x) {
        if (root == nullptr || root->val == x) return root;
        TreeNode* res = find(root->left, x);
        if (res != nullptr) {
            return res;
        }
        return find(root->right, x);
    }

    int count(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + count(root->left) + count(root->right);
    }
};
```

### 复杂度分析

时间复杂度：$O(n)$，其中 $n$ 是二叉树节点的数量，每个节点至多遍历一次。

空间复杂度：$O(n)$，递归遍历消耗的栈空间，最好的情况下需要遍历 $O(logn)$，最坏的情况下需要遍历 $O(n)$。