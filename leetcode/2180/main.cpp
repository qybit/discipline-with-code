/*
 * @Author: qybit 2601970213@qq.com
 * @Date: 2023-01-07 19:32:17
 * @LastEditors: qybit 2601970213@qq.com
 * @LastEditTime: 2023-01-07 19:32:45
 * @FilePath: \discipline-with-code\2180\main.cpp
 */
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countEven(int num)
    {
        int ans = 0;
        for (int x = 1; x <= num; x++)
        {
            int s = cal(x);
            if ((s & 1) == 0)
                ans++;
        }
        return ans;
    }

    int cal(int x)
    {
        int s = 0;
        while (x != 0)
        {
            s += x % 10;
            x /= 10;
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