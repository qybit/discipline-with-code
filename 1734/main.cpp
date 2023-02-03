#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> decode(vector<int> &encoded)
    {
        int sz = encoded.size();
        int n = sz + 1;
        int a = 0;
        for (int i = 1; i <= n; i++)
        {
            a ^= i;
        }
        for (int i = 1; i < sz; i += 2)
        {
            a ^= encoded[i];
        }
        vector<int> ans(n);
        ans[0] = a;
        for (int i = 0; i < n - 1; i++)
        {
            ans[i + 1] = ans[i] ^ encoded[i];
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