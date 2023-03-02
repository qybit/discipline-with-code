#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string greatestLetter(string s)
    {
        unordered_set<char> m(s.begin(), s.end());
        for (int i = 25; i >= 0; i--)
        {
            if (m.count(i + 'A') > 0 && m.count(i + 'a') > 0)
            {
                return string(1, i + 'A');
            }
        }
        return "";
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