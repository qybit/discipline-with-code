#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> countPoints(vector<vector<int>> &points, vector<vector<int>> &queries)
    {
        int n = queries.size();
        vector<int> ans;
        for (auto &&q : queries)
        {
            int rx = q[0], ry = q[1], d = q[2];
            int count = 0;
            for (auto &&p : points)
            {
                int x = p[0], y = p[1];
                bool isIn = (rx - x) * (rx - x) + (ry - y) * (ry - y) <= d * d;
                if (isIn)
                {
                    count++;
                }
            }
            ans.push_back(count);
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