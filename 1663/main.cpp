#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string getSmallestString(int n, int k)
    {
        string s(n, 'a');
        k -= n;
        for (int i = n - 1; i >= 0; i--)
        {
            if (k > 25)
            {
                s[i] = 'z';
                k -= 25;
            }
            else
            {
                s[i] = (char)(k + 'a');
                break;
            }
        }
        return s;
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