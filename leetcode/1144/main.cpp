#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int n;
    int movesToMakeZigzag(vector<int> &nums)
    {
        n = nums.size();
        return min(f1(nums), f2(nums));
    }

    // 偶数
    int f1(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 1; i < n; i += 2)
        {
            int num1 = nums[i - 1];
            int num2 = i + 1 < n ? nums[i + 1] : INT_MAX;
            int x = min(num1, num2);
            if (nums[i] >= x)
                ans += nums[i] - x + 1;
        }
        return ans;
    }
    // 奇数
    int f2(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < n; i += 2)
        {
            int num1 = i + 1 < n ? nums[i + 1] : INT_MAX;
            int num2 = i > 0 ? nums[i - 1] : INT_MAX;
            int x = min(num1, num2);
            if (nums[i] >= x)
                ans += nums[i] - x + 1;
        }
        return ans;
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