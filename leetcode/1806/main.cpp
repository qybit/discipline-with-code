#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int reinitializePermutation(int n)
    {
        vector<int> arr(n);
        vector<int> perm(n);
        int ans = 0;
        for (int i = 0; i < n; i++)
            perm[i] = i;
        do
        {
            for (int i = 0; i < n; i++)
            {
                if (i % 2 == 0)
                {
                    arr[i] = perm[i / 2];
                }
                else
                {
                    arr[i] = perm[n / 2 + (i - 1) / 2];
                }
            }
            perm = arr;
            ans++;
        } while (valid(perm));
        return ans;
    }

    bool valid(vector<int> &arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] != i)
                return true;
        }
        return false;
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