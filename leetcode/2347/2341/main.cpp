#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    vector<int> numberOfPairs(vector<int> &nums)
    {
        unordered_map<int, bool> m;
        int ans = 0, n = nums.size();
        for (int num : nums)
        {
            if (m.count(num))
            {
                m[num] = !m[num];
            }
            else
            {
                m[num] = true;
            }
            if (!m[num])
            {
                ans++;
            }
        }
        return {ans, n - ans * 2};
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