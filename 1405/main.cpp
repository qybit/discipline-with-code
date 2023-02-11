#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        string ans;
        vector<pair<int, char>> m{{a, 'a'}, {b, 'b'}, {c, 'c'}};
        while (true)
        {
            sort(rbegin(m), rend(m));
            int pre_sz = ans.size();
            for (auto &[cnt, c] : m)
            {
                if (cnt <= 0 || ans.size() >= 2 && c == ans.back() && c == ans[ans.size() - 2])
                    continue;
                ans += c;
                cnt--;
                break;
            }
            if (pre_sz == ans.size())
                break;
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