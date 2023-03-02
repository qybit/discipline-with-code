#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int fillCups(vector<int> &amount)
    {
        int ans = 0;
        while (true)
        {
            sort(amount.begin(), amount.end());
            if (amount[2] <= 0)
            {
                break;
            }
            amount[2]--, amount[1]--;
            ans++;
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