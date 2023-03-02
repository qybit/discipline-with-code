#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int dirs4[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    int m, n;
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        this->m = m;
        this->n = n;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    ans = max(ans, dfs(i, j, grid));
                }
            }
        }
        return ans;
    }

    int dfs(int i, int j, vector<vector<int>> &grid)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1)
            return 0;
        grid[i][j] = -1;
        int res = 1;
        for (auto dir : dirs4)
        {
            int x = i + dir[0], y = j + dir[1];
            res += dfs(x, y, grid);
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