#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int balancedString(string s)
    {
        vector<int> cnt(26);
        for (char c : s)
            cnt[c - 'A']++;
        int n = s.size();
        int avg = n / 4;
        int l = 0, r = 0;
        int ans = INT_MAX;
        while (r < n)
        {
            cnt[s[r] - 'A']--;
            while (l < n && cnt['Q' - 'A'] <= avg && cnt['W' - 'A'] <= avg && cnt['E' - 'A'] <= avg && cnt['R' - 'A'] <= avg)
            {
                ans = min(ans, r - l + 1);
                cnt[s[l++] - 'A']++;
            }
            r++;
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