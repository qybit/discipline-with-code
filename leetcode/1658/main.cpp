/*
 * @Author: qybit 2601970213@qq.com
 * @Date: 2023-01-07 19:34:40
 * @LastEditors: qybit 2601970213@qq.com
 * @LastEditTime: 2023-01-07 19:52:33
 * @FilePath: \discipline-with-code\1658\main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int sum = 0;
        int n = nums.size();
        for (auto &x : nums)
            sum += x;
        if (sum < x)
            return -1;
        int lsum = 0, rsum = sum;
        int l = -1, r = 0;
        int ans = n + 1;
        while (l < n)
        {
            if (l != -1)
            {
                lsum += nums[l];
            }
            while (r < n && lsum + rsum > x)
            {
                rsum -= nums[r];
                r++;
            }

            if (lsum + rsum == x)
            {
                ans = min(ans, (l + 1) + (n - r));
            }
            l++;
        }
        return ans > n ? -1 : ans;
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