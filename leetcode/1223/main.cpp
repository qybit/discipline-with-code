#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    static constexpr int mod = 1E9 + 7;
    int dieSimulator(int n, vector<int> &rollMax)
    {
        vector d(2, vector(6, vector<int>(16)));
        for (int j = 0; j < 6; j++)
        {
            d[1][j][1] = 1;
        }
        for (int i = 2; i <= n; i++)
        {
            int t = i & 1;
            for (int j = 0; j < 6; j++)
            {
                fill(d[t][j].begin(), d[t][j].end(), 0);
            }
            for (int j = 0; j < 6; j++)
            {
                for (int k = 1; k <= rollMax[j]; k++)
                {
                    for (int p = 0; p < 6; p++)
                    {
                        if (p != j)
                        {
                            d[t][p][1] = (d[t][p][1] + d[t ^ 1][j][k]) % mod;
                        }
                        else if (k + 1 <= rollMax[j])
                        {
                            d[t][p][k + 1] = (d[t][p][k + 1] + d[t ^ 1][j][k]) % mod;
                        }
                    }
                }
            }
        }

        int res = 0;
        for (int j = 0; j < 6; j++)
        {
            for (int k = 1; k <= rollMax[j]; k++)
            {
                res = (res + d[n & 1][j][k]) % mod;
            }
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