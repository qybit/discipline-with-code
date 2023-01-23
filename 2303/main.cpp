#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    double calculateTax(vector<vector<int>> &brackets, int income)
    {
        if (income == 0)
            return 0.0;
        int total = 0;
        int preUpper = 0;
        for (auto &bracket : brackets)
        {
            int upper = bracket[0];
            double rate = bracket[1];
            if (income >= upper)
            {
                total += (upper - preUpper) * rate;
                preUpper = upper;
            }
            else
            {
                total += (income - preUpper) * rate;
                break;
            }
        }
        return (double)total / 100;
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