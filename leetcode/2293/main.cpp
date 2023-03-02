#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minMaxGame(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        while (n != 1)
        {
            vector<int> t(n / 2);
            for (int i = 0; i < n / 2; i++)
            {
                if (i % 2 == 0)
                {
                    t[i] = min(nums[2 * i], nums[2 * i + 1]);
                }
                else
                {
                    t[i] = max(nums[2 * i], nums[2 * i + 1]);
                }
            }
            nums = t;
            n /= 2;
        }
        return nums[0];
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