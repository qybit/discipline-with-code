#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minSideJumps(vector<int> &obstacles)
    {
        int n = obstacles.size();
        vector<int> dp{1, 0, 1};
        const int inf = 1e9;
        for (int i = 0; i < n; i++)
        {
            int count = inf;
            for (int j = 0; j < 3; j++)
            {
                if (j == obstacles[i] - 1)
                {
                    dp[j] = inf;
                }
                else
                {
                    count = min(count, dp[j]);
                }
            }
            for (int j = 0; j < 3; j++)
            {
                if (j == obstacles[i] - 1)
                {
                    continue;
                }
                else
                {
                    dp[j] = min(count + 1, dp[j]);
                }
            }
        }
        return *min_element(dp.begin(), dp.end());
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