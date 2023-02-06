题目链接：[2331. 计算布尔二叉树的值](https://leetcode.cn/problems/evaluate-boolean-binary-tree/)

## 递归

根据题意，本题中的二叉树是一个完整二叉树，其中叶子节点的值只有 $0$ 或 $1$，分别表示 $false$ 和 $true$。非叶子节点表示对其子节点的操作，当值为 $2$ 时表示子节点的逻辑或，$3$ 时表示子节点的逻辑与。可以对这个子问题进行递归处理：

- 叶子节点可以直接返回它自己本身代表的 $true$ 或 $false$。
- 非叶子节点则是先获取其左子树的计算和，再获取右子树的计算和，再按照当前节点的值进行逻辑或操作或逻辑与操作，最后返回结果。

Code

```c++
class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if (root->val == 2) {
            return evaluateTree(root->left) || evaluateTree(root->right);
        } else if (root->val == 3) {
            return evaluateTree(root->left) && evaluateTree(root->right);
        } else if (root->val == 1) {
            return true;
        } 
        return false;
    }
};
```

### 复杂度分析

时间复杂度：$O(n)$，其中 $n$ 表示二叉树节点的数量。

空间复杂度：$O(n)$，表示栈递归使用的内存空间。