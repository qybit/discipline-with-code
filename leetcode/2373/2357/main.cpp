#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        int ans = 0;
        while (true)
        {
            sort(nums.begin(), nums.end());
            int x = 0;
            for (int num : nums)
            {
                if (num != 0)
                {
                    x = num;
                    break;
                }
            }
            if (x == 0)
                break;
            for (int &num : nums)
            {
                if (num > 0)
                {
                    num -= x;
                }
            }
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