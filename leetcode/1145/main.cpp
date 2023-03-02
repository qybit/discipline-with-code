#include <bits/stdc++.h>

using namespace std;

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
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    bool btreeGameWinningMove(TreeNode *root, int n, int x)
    {
        TreeNode *xNode = find(root, x); // 找到x节点
        int l = count(xNode->left), r = count(xNode->right);
        return max({l, r, n - l - r - 1}) > n / 2;
    }

    TreeNode *find(TreeNode *root, int x)
    {
        if (root == nullptr || root->val == x)
            return root;
        TreeNode *res = find(root->left, x);
        if (res != nullptr)
        {
            return res;
        }
        return find(root->right, x);
    }

    int count(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return 1 + count(root->left) + count(root->right);
    }
};

void solve()
{
    Solution *s = new Solution();
}
int main()
{
    solve();
    return 0;
}