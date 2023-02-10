#include <bits/stdc++.h>
/**
 * @param x [int]类型数字 e.g. x=123
 * @return 反转后的数字 e.g. 321
*/
int reverseNum(int x)
{
    int res = 0;
    while (x != 0)
    {
        int q = x % 10;
        if (res > INT_MAX / 10 || (res == INT_MAX / 10 && q > 7)) return 0;
        if (res < INT_MIN / 10 || (res == INT_MIN / 10 && q < -8)) return 0;
        res = res * 10 + q;
        x /= 10;
    }
    return res;
}