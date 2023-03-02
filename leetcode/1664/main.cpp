#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int waysToMakeFair(vector<int> &nums)
    {
        int n = nums.size();
        // 原始状态下奇偶之和
        int ori_odd = 0, ori_even = 0;
        for (int i = 0; i < n; i++)
        {
            if (i & 1)
            {
                ori_odd += nums[i];
            }
            else
            {
                ori_even += nums[i];
            }
        }
        int res = 0;
        int left_odd = 0, left_even = 0;
        for (int i = 0; i < n; i++)
        {
            int new_odd = ori_odd - left_odd - (i & 1 ? nums[i] : 0) + left_even;
            int new_even = ori_even - left_even - (i & 1 ? 0 : nums[i]) + left_odd;
            if (new_even == new_odd)
                res++;
            i & 1 ? left_odd += nums[i] : left_even += nums[i];
        }
        return res;
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