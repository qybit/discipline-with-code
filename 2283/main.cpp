#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    bool digitCount(string num)
    {
        int ans = 0;
        int n = num.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[num[i] - '0']++;
        }
        for (int i = 0; i < n; i++)
        {
            int count = m[i], x = num[i] - '0';
            if (count != x)
                return false;
        }
        return true;
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