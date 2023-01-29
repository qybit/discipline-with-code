#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countAsterisks(string s)
    {
        bool f = true;
        int ans = 0;
        for (char c : s)
        {
            if (c == '|')
            {
                f = !f;
            }
            else if (c == '*')
            {
                if (f)
                    ans++;
            }
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