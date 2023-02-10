/**
 * @param x [int]类型数字 e.g. x=123
 * @return 反转后的数字 e.g. 321
*/
int reverseNum(int x)
{
    int a = 0;
    while (x != 0)
    {
        a = a * 10 + x % 10;
        x /= 10;
    }
    return a;
}