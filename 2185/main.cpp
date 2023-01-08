#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int prefixCount(vector<string> &words, string pref)
    {
        int ans = 0;
        for (auto& word : words) {
            if (word.rfind(pref, 0) == 0) ans ++;
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