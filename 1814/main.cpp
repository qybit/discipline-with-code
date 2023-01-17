#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int reverseNum(int x)
    {
        int a = 0;
        while (x != 0)
        {
            a = a * 10 + x % 10;
            x /= 10;
        }
        return a;
    }

    int countNicePairs(vector<int> &nums)
    {
        const int MOD = 1e9 + 7;
        int ans = 0, n = nums.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            int x = nums[i], y = reverseNum(nums[i]);
            int f = x - y;
            ans = (ans + m[f]) % MOD;
            m[f]++;
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