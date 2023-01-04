/*
 * @Author: qybit 2601970213@qq.com
 * @Date: 2023-01-04 23:04:07
 * @LastEditors: qybit 2601970213@qq.com
 * @LastEditTime: 2023-01-04 23:27:19
 * @FilePath: \discipline-with-code\1802\main.cpp
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

class Solution
{
public:
    int maxValue(int n, int index, int maxSum)
    {
        int leftCount = index, rightCount = n - index - 1;
        int l = 1, r = maxSum;
        while (l <= r)
        {
            int m = (l + r) >> 1;
            LL sum = m + getSum(m, leftCount) + getSum(m, rightCount);
            if (sum > maxSum)
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        return l - 1;
    }

    LL getSum(int x, int k)
    {
        if (x > k)
            return (LL)k * (2 * x - 1 - k) / 2;
        return (LL)x * (x - 3) / 2 + k + 1;
    }
};

void solve()
{
    Solution *s = new Solution();
    int ret = s->maxValue(8257285, 4828516, 850015631);
    cout << ret << endl;
}
int main()
{
    solve();
    return 0;
}