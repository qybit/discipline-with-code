#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int rearrangeCharacters(string s, string target)
    {
        unordered_map<char, int> m1, m2;
        for (char c : s)
        {
            m1[c]++;
        }
        int ans = INT_MAX;
        for (char c : target)
        {
            m2[c]++;
        }
        for (char c : target)
        {
            int t = m1[c] / m2[c];
            ans = min(ans, t);
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