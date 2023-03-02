#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    bool isGoodArray(vector<int> &nums)
    {
        int q = nums[0];
        for (int num : nums)
        {
            q = gcd(num, q);
            if (q == 1)
            {
                return true;
            }
        }
        return false;
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