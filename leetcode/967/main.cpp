#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> ans;
    int cur = 0;
    const int N = 9;
    int n, k;

    void backtrace(int pos)
    {
        if (pos >= n)
        {
            ans.emplace_back(cur);
            return;
        }
        for (int x = 0; x <= N; x++)
        {
            if (pos == 0 && x == 0)
                continue; // 前导0
            if (cur > 0)
            {
                if (abs(x - (cur % 10)) != k)
                    continue;
            }
            cur = cur * 10 + x;
            backtrace(pos + 1);
            cur /= 10;
        }
    }

    vector<int> numsSameConsecDiff(int _n, int _k)
    {
        n = _n, k = _k;
        backtrace(0);
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