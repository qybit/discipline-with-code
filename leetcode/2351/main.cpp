#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    char repeatedCharacter(string s)
    {
        unordered_map<char, int> m;
        for (char &c : s)
        {
            if (m.count(c) == 1)
            {
                return c;
            }
            m[c]++;
        }
        return ' ';
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